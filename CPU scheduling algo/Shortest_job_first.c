#include <stdio.h>

int main() {
    int n, i, j, pos, temp;
    int burstTime[20], waitingTime[20], turnAroundTime[20];
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // Sorting burst time in ascending order (SJF scheduling)
    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i + 1; j < n; j++) {
            if(burstTime[j] < burstTime[pos])
                pos = j;
        }

        // Swapping burst times
        temp = burstTime[i];
        burstTime[i] = burstTime[pos];
        burstTime[pos] = temp;
    }

    // Calculate waiting time
    waitingTime[0] = 0;
    for(i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }

    // Display results
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

Enter the number of processes: 5
Enter burst time for each process:
Process 1: 3
Process 2: 5
Process 3: 1
Process 4: 5
Process 5: 8

Process Burst Time      Waiting Time    Turnaround Time
1               1               0               1
2               3               1               4
3               5               4               9
4               5               9               14
5               8               14              22

Average Waiting Time: 5.60
Average Turnaround Time: 10.00

*/


