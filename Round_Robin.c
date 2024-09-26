#include <stdio.h>

int main() {
    int i, n, quantum, total = 0, counter = 0, time = 0;
    int burstTime[10], remainingTime[10], waitingTime[10], turnAroundTime[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];  // Initially, remaining time is the same as burst time
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while(1) {
        for(i = 0, counter = 0; i < n; i++) {
            if(remainingTime[i] > 0) { // if process i still has some time left 
                if(remainingTime[i] > quantum) { // If the remaining burst time of the process is greater than the time quantum, it means the process needs more time than the current quantum to finish.
                    time += quantum;
                    remainingTime[i] -= quantum;
                } else { // If the remaining burst time is less than or equal to the quantum, the process can finish in this round.
                    time += remainingTime[i];
                    waitingTime[i] = time - burstTime[i]; // if we minus bursttime from the total time then we will get the waiting time of the process.
                    remainingTime[i] = 0;
                }
            }
        }

        // Check if all processes are done
        for(i = 0; i < n; i++) {
            if(remainingTime[i] > 0)
                counter++;
        }
        if(counter == 0)  // All processes completed
            break;
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    return 0;
}

/*

Enter the number of processes: 6
Enter burst time for each process:
Process 1: 3
Process 2: 4
Process 3: 2
Process 4: 6
Process 5: 9
Process 6: 10
Enter time quantum: 4

Process Burst Time      Waiting Time    Turnaround Time
1               3               0               3
2               4               3               7
3               2               7               9
4               6               17              23
5               9               23              32
6               10              24              34

*/


