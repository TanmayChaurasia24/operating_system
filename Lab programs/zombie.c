// A zombie process or defunct process is a process
// that has completed execution but still has an entry
// in the process table.

// • A zombie process occurs when a child process
// has finished execution, but the parent process
// has not yet called wait() or waitpid() to collect
// its termination status.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork(); // create a new child process
    if (pid > 0)
    {
        // Parent process doesn't call wait(), causing child to become a zombie
        printf("Parent process sleeping for 10 seconds...\n");
        sleep(10); // Sleep so child becomes a zombie before being cleaned
    }
    else if (pid == 0)
    {
        // Child process finishes immediately, becoming a zombie
        printf("Child process finished execution.\n");
        exit(0); // Child process terminates
    }
    else
    {
        printf("Fork failed.\n");
    }
    return 0;
}

// open a new terminal and run either ps aux or top to observe the zombie process.