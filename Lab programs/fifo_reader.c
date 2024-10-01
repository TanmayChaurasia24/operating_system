#include<stdio.h>       // Standard Input/Output library for printf, scanf, etc.
#include<string.h>      // Library for string manipulation functions like strlen
#include<sys/stat.h>    // For system calls related to file attributes, including mknod
#include<fcntl.h>       // For file control operations like open()

int main() {
    int fd, nbr;       // 'fd' for file descriptor, 'nbr' for number of bytes read
    char arr[100];     // 'arr' is a character array to hold the data read from the pipe

    // Creating a FIFO (named pipe) using 'mknod' system call
    // S_IFIFO specifies that it's a FIFO, and 0666 is the permission (read/write for everyone)
    mknod("myfifo", S_IFIFO | 0666, 0);

    // Open the FIFO for reading only (O_RDONLY)
    // This means the process will read data sent by another process (the writer)
    fd = open("myfifo", O_RDONLY);

    // Print message to indicate the reader is ready to receive data
    printf("If you got a writer process then type some data\n");

    // Start a loop to continuously read data from the FIFO
    // The 'read' function reads data from 'fd' (file descriptor of FIFO) into the 'arr' buffer
    // It reads up to the size of 'arr' (100 bytes)
    do {
        nbr = read(fd, arr, sizeof(arr));   // Read data from FIFO
        arr[nbr] = '\0';                    // Append a null terminator to make it a valid string
        
        // Print the number of bytes read and the content
        printf("Reader process read %d bytes: %s\n", nbr, arr);
    } while(nbr > 0);  // Continue reading as long as the number of bytes read is greater than 0

    // When no more data is read (nbr <= 0), the loop will exit and the program ends

    return 0;  // End of the program, return 0 indicating successful completion
}
