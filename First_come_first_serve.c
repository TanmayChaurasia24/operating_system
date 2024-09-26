#include <stdio.h>

int main() {
    int n, i;
    int burstTime[20], waitingTime[20], turnAroundTime[20];
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // Calculate waiting time
    waitingTime[0] = 0;  // First process has no waiting time
    for(i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    // Calculate turn around time
    for(i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnAroundTime / n);

    return 0;
}

/*
Enter the number of processes: 4
Enter burst time for each process:
Process 1: 4
Process 2: 2
Process 3: 5
Process 4: 3

Process Burst Time      Waiting Time    Turnaround Time
1               4               0               4
2               2               4               6
3               5               6               11
4               3               11              14

Average Waiting Time: 5.25
Average Turnaround Time: 8.75

*/