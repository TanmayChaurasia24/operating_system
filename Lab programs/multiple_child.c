#include <stdio.h>     // For standard input-output functions like printf
#include <stdlib.h>    // For functions like exit()
#include <sys/types.h> // Defines types like pid_t (used for process IDs)
#include <sys/wait.h>  // For wait() system call, used by parent to wait for child processes
#include <unistd.h>    // For fork(), getpid(), sleep() functions

#define NUM_CHILDREN 3  // Number of child processes to create

int main() {
    pid_t pids[NUM_CHILDREN];  // Array to store the PIDs of the child processes
    int i;

    // Fork multiple child processes in a loop
    for (i = 0; i < NUM_CHILDREN; i++) {
        pids[i] = fork();  // Create a new child process

        if (pids[i] < 0) {
            // If fork() returns a negative value, the process creation failed
            fprintf(stderr, "Fork Failed\n");
            return 1;  // Return non-zero to indicate failure
        } else if (pids[i] == 0) {
            // This block is executed by the child process (pid == 0)
            printf("Child %d: PID = %d\n", i, getpid());  // Print the child number and its PID
            sleep(10);  // Simulate some work by sleeping for 10 seconds
            printf("Child %d: Exiting\n", i);  // Indicate that the child process is exiting
            exit(0);  // Exit the child process after completing its work
        }
        // Parent process continues the loop to create more children
    }

    // Parent process waits for all child processes to complete
    for (i = 0; i < NUM_CHILDREN; i++) {
        wait(NULL);  // Wait for any child process to complete
    }

    // After all child processes have finished
    printf("Parent Process: All children have completed\n");

    return 0;  // Return 0 to indicate successful execution
}

/*
Expected Output:

Child 0: PID = 12345       // Child 0 process starts (PID is an example, it will vary each run)
Child 1: PID = 12346       // Child 1 process starts
Child 2: PID = 12347       // Child 2 process starts
(After 10 seconds)
Child 0: Exiting           // Child 0 exits after finishing its work
Child 1: Exiting           // Child 1 exits after finishing its work
Child 2: Exiting           // Child 2 exits after finishing its work
Parent Process: All children have completed

Explanation:
1. The parent process creates 3 child processes in a loop using `fork()`.
2. Each child process prints its PID and sleeps for 10 seconds, simulating work.
3. After the sleep period, each child process exits.
4. The parent process waits for all 3 child processes to finish using `wait()`.
5. Once all child processes have exited, the parent process prints a message that all children have completed.
*/
