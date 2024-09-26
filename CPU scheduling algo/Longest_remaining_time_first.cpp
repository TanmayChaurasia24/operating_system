// The Longest Remaining Time First (LRTF) algorithm is a preemptive CPU scheduling algorithm. In this algorithm, the process with the longest remaining burst time (execution time) gets the CPU next. If a new process arrives with a longer burst time than the current process, the current process is preempted and moved back to the ready queue, and the new process gets the CPU.

#include <iostream> 
using namespace std; 

// Define a structure to represent each process
struct Process {
    int id;             // Process ID
    int arrivalTime;    // Time at which the process arrives in the system
    int burstTime;      // Total time required by the process
    int remainingTime;  // Time remaining for the process to complete
    int completionTime; // Time at which the process completes its execution
};

int main() {
    int n;              // Number of processes
    int time = 0;      // Current time in the scheduling process
    int largest;       // Index of the process with the longest remaining time
    int remain = 0;    // Count of processes that have completed
    float totalWaitTime = 0;      // Total waiting time of all processes
    float totalTurnaroundTime = 0; // Total turnaround time of all processes

    cout << "Enter the number of processes: ";
    cin >> n; // Input the number of processes

    Process processes[n]; // Declare an array to hold the process information

    // Input each process's arrival and burst time
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process P" << i + 1 << ": ";
        processes[i].id = i + 1; // Assign process ID
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime; // Initialize remaining time
    }

    // Main scheduling loop, continues until all processes are completed
    while (remain != n) {
        largest = -1; // Reset the largest index for each time unit

        // Check for the process with the longest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            // Process must have arrived and not yet completed
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0) {
                // Update largest if we find a process with longer remaining time
                if (largest == -1 || processes[i].remainingTime > processes[largest].remainingTime) {
                    largest = i; // Update the index of the longest remaining time process
                }
            }
        }

        // If a valid process is found
        if (largest != -1) {
            processes[largest].remainingTime--; // Decrease remaining time by 1

            // Check if the current process has completed
            if (processes[largest].remainingTime == 0) {
                remain++; // Increment completed process count
                // Set completion time for the finished process
                processes[largest].completionTime = time + 1;
                // Calculate waiting time for this process
                totalWaitTime += processes[largest].completionTime - processes[largest].arrivalTime - processes[largest].burstTime;
                // Calculate turnaround time for this process
                totalTurnaroundTime += processes[largest].completionTime - processes[largest].arrivalTime;
            }
        }
        time++; // Move to the next time unit
    }

    // Output the results
    cout << "\nProcess ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time\n";
    for (int i = 0; i < n; i++) {
        // Calculate turnaround time and waiting time for each process
        int turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        int waitingTime = turnaroundTime - processes[i].burstTime;
        // Print the details for each process
        cout << "P" << processes[i].id << "         | " << processes[i].arrivalTime 
             << "           | " << processes[i].burstTime << "         | " 
             << processes[i].completionTime << "              | " 
             << turnaroundTime << "              | " << waitingTime << endl;
    }

    // Print average waiting time and average turnaround time
    cout << "\nAverage Waiting Time: " << totalWaitTime / n;
    cout << "\nAverage Turnaround Time: " << totalTurnaroundTime / n;

    return 0; // Exit the program
}

/*

Enter the number of processes: 5
Enter arrival time and burst time for process P1: 0
4
Enter arrival time and burst time for process P2: 3
5
Enter arrival time and burst time for process P3: 6

7
Enter arrival time and burst time for process P4: 3
5
Enter arrival time and burst time for process P5: 6
9

Process ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time
P1         | 0           | 4         | 26              | 26              | 22
P2         | 3           | 5         | 27              | 24              | 19
P3         | 6           | 7         | 28              | 22              | 15
P4         | 3           | 5         | 29              | 26              | 21
P5         | 6           | 9         | 30              | 24              | 15

Average Waiting Time: 18.4
Average Turnaround Time: 24.4



*/


