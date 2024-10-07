# Communication Between Two Processes Using Signals in C

This document contains a C program demonstrating communication between a parent and child process using signals. The child process responds to signals sent by the parent process.

## Code

```c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Function declarations for signal handlers
void sighup();
void sigint();
void sigquit();

// Driver code
int main()
{
    int pid;

    /* Get child process */
    if ((pid = fork()) < 0) {
        perror("fork"); // Handle fork error
        exit(1);
    }

    if (pid == 0) { /* Child process */
        // Set up signal handlers
        signal(SIGHUP, sighup);  // Handle SIGHUP signal
        signal(SIGINT, sigint);  // Handle SIGINT signal
        signal(SIGQUIT, sigquit); // Handle SIGQUIT signal
        
        // Infinite loop to keep the child process running
        for (;;) 
            ; // Loop forever
    } 
    else { /* Parent process */
        // pid holds the ID of the child
        printf("\nPARENT: sending SIGHUP\n\n");
        kill(pid, SIGHUP); // Send SIGHUP signal to the child

        sleep(3); /* Pause for 3 seconds */
        printf("\nPARENT: sending SIGINT\n\n");
        kill(pid, SIGINT); // Send SIGINT signal to the child

        sleep(3); /* Pause for 3 seconds */
        printf("\nPARENT: sending SIGQUIT\n\n");
        kill(pid, SIGQUIT); // Send SIGQUIT signal to the child
        sleep(3); // Wait for a moment before exiting
    }
    return 0; // Return 0 to indicate successful execution
}

// SIGHUP signal handler function definition
void sighup() {
    signal(SIGHUP, sighup); // Reset signal handler for SIGHUP
    printf("CHILD: I have received a SIGHUP\n"); // Notify reception of SIGHUP
}

// SIGINT signal handler function definition
void sigint() {
    signal(SIGINT, sigint); // Reset signal handler for SIGINT
    printf("CHILD: I have received a SIGINT\n"); // Notify reception of SIGINT
}

// SIGQUIT signal handler function definition
void sigquit() {
    printf("My DADDY has Killed me!!!\n"); // Notify that the child is exiting
    exit(0); // Exit the child process
}
