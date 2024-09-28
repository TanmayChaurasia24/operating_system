#include <stdio.h>    // Required for standard I/O functions like printf
#include <unistd.h>   // Provides pipe, fork, and read/write functions
#include <stdlib.h>   // Provides exit function for error handling

int main() {
    int pipefd[2];     // Array to hold file descriptors for the pipe: pipefd[0] for reading, pipefd[1] for writing
    pid_t pid;         // Variable to hold the process ID returned by fork()
    char buffer[30];   // Buffer to store data read from the pipe

    // Create the pipe
    if (pipe(pipefd) == -1) {   // pipe() returns -1 if an error occurs
        perror("Pipe failed");  // Print the error if pipe creation fails
        exit(EXIT_FAILURE);     // Exit the program with failure status
    }

    // Fork the process to create a child process
    pid = fork();    // fork() returns 0 in the child process, and the PID of the child in the parent
    if (pid == -1) { // If fork() returns -1, the process creation has failed
        perror("Fork failed");  // Print the error if forking fails
        exit(EXIT_FAILURE);     // Exit the program with failure status
    }

    if (pid == 0) {
        // Child process
        close(pipefd[1]);  // Close the write end of the pipe, as the child only needs to read

        // Read data from the pipe
        read(pipefd[0], buffer, sizeof(buffer)); // Read the data written by the parent into the buffer

        // Output the data that the child process received from the pipe
        printf("Child process received: %s\n", buffer);

        // Close the read end of the pipe after reading the data
        close(pipefd[0]);

    } else {
        // Parent process
        close(pipefd[0]);  // Close the read end of the pipe, as the parent only needs to write

        // Write data to the pipe
        write(pipefd[1], "Hello from parent!", 18);  // The parent writes a message to the pipe

        // Close the write end of the pipe after sending the data
        close(pipefd[1]);

        // Wait for the child process to finish
        wait(NULL);  // The parent process waits for the child process to complete before terminating
    }

    return 0;  // Exit the program
}
