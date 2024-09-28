#include <stdio.h>     // For standard input-output functions like printf
#include <stdlib.h>    // For functions like exit()
#include <sys/types.h> // Defines types like pid_t (used for process IDs)
#include <sys/wait.h>  // For the wait() system call (used in parent process to wait for child process)
#include <unistd.h>    // For fork(), getpid(), getppid(), sleep() functions

int main() {
    pid_t pid = fork();  // Create a new process by duplicating the calling process

    if (pid < 0) {
        // If fork() returns a negative value, it means the process creation failed
        fprintf(stderr, "Fork Failed\n");
        return 1;  // Non-zero return value to indicate error
    } else if (pid == 0) {
        // This block is executed by the child process (pid == 0)
        printf("Child Process: PID = %d\n", getpid());     // Print the child process ID
        printf("Child Process: Parent PID = %d\n", getppid()); // Print the parent process ID
        sleep(10);  // Simulate some work with a 10-second sleep
        printf("Child Process: Exiting\n");  // Indicate that the child process is exiting
        exit(0);   // Exit the child process
    } else {
        // This block is executed by the parent process (pid > 0)
        printf("Parent Process: Waiting for child to complete\n");
        wait(NULL);  // Wait for the child process to terminate
        printf("Parent Process: Child has completed\n");
    }

    return 0;  // Return 0 to indicate successful execution
}

/*
Expected Output:

Parent Process: Waiting for child to complete
Child Process: PID = 12346           
Child Process: Parent PID = 12345       
Child Process: Exiting
Parent Process: Child has completed


*/
