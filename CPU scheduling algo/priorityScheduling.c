#include <stdio.h>

// Structure to represent a process
struct Process {
    int id;       // Process ID
    int burstTime; // Burst Time (Execution Time)
    int priority;  // Priority of the process
    int waitingTime; // Waiting Time
    int turnaroundTime; // Turnaround Time
};

// Function to sort processes by priority
void sortProcessesByPriority(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                // Swap processes[j] and processes[j+1]
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to calculate waiting time for each process
void calculateWaitingTime(struct Process processes[], int n) {
    processes[0].waitingTime = 0; // The first process has no waiting time
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

// Function to calculate turnaround time for each process
void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

// Function to print the details of each process
void printProcessDetails(struct Process processes[], int n) {
    printf("\nProcess ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].priority,
               processes[i].burstTime,
               processes[i].waitingTime,
               processes[i].turnaroundTime);
    }
}

int main() {
    int n;

    // Input: Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n]; // Array to store process details

    // Input: Process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assign a unique process ID
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter Priority for Process %d (Lower number indicates higher priority): ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    // Step 1: Sort processes based on priority
    sortProcessesByPriority(processes, n);

    // Step 2: Calculate waiting time for each process
    calculateWaitingTime(processes, n);

    // Step 3: Calculate turnaround time for each process
    calculateTurnaroundTime(processes, n);

    // Step 4: Print process details and results
    printProcessDetails(processes, n);

    // Calculate and print average waiting time and turnaround time
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);

    return 0;
}
