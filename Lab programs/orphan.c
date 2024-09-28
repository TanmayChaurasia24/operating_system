#include<stdio.h>   // Standard input-output functions like printf
#include<unistd.h>  // Contains fork(), getpid(), getppid(), sleep() functions

int main() {
    pid_t pid;      // Declaring a variable to hold the process ID
    pid = fork();   // Create a new process by duplicating the calling process

    // The fork() function returns a different value in the parent and child processes:
    // - If pid == 0, this is the child process
    // - If pid > 0, this is the parent process (pid contains the PID of the child)
    if(pid == 0) {
        // Child process code block
        sleep(6);  // Make the child process sleep for 6 seconds to simulate some delay
        printf("\nI am the child, my PID = %d and my parent's PID (PPID) = %d", getpid(), getppid());
        // getpid() returns the process ID of the current process (child)
        // getppid() returns the parent process ID
    } else {
        // Parent process code block
        printf("I am the parent, my child's PID = %d and my PID = %d", pid, getpid());
        // pid contains the child's process ID, and getpid() returns the parent's process ID
    }

    // Both child and parent processes execute this statement after their respective blocks
    printf("\nTerminating PID = %d\n", getpid());
    // This will print the terminating process's ID (child or parent, depending on which process is running)

    return 0;  // Return 0 to indicate successful execution
}

/*
Expected Output:

I am the parent, my child's PID = 12346 and my PID = 12345
Terminating PID = 12345
(After 6 seconds)
I am the child, my PID = 12346 and my parent's PID (PPID) = 12345
Terminating PID = 12346

*/
