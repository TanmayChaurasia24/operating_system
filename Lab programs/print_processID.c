#include<stdio.h>   // Standard input-output header for printf() function
#include<sys/types.h> // Defines types used in system calls (e.g., pid_t for process ID)
#include<unistd.h>    // Contains declarations for fork(), getpid(), etc.

int main() {
    // fork() creates a new process by duplicating the calling process
    pid_t p = fork();  // fork() returns a process ID (pid_t is the type of process ID)
    
    // If fork() returns a negative value, there was an error in creating the process
    if(p < 0) {
        perror("fork fail"); // Print the error message if fork fails
        exit(1);             // Exit the program with a non-zero status indicating failure
    }

    // This line is executed by both the parent and child process.
    // getpid() returns the process ID of the calling process
    printf("hello world!, process_id(pid) = %d\n", getpid());

    return 0;  // Return 0 to indicate successful execution
}



/*
OUTPUT

// PID may vary on different systems
hello world!, process_id(pid) = 12345  
hello world!, process_id(pid) = 12346  


*/

