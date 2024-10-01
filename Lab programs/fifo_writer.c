#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
    int fd,nbw; //int fd, nbw;: fd is a file descriptor that will store the identifier for the opened FIFO file. nbw will store the number of bytes written when we write to the FIFO.
    char str[100]; // char str[100];: This is a character array (string) that will hold the input from the user, which will then be written into the FIFO file.


    // mknod: This function is used to create special files like FIFOs, device files, or other files.
    // "myfifo": This is the name of the FIFO file that will be created.
    // S_IFIFO | 0666: S_IFIFO is a flag that specifies that the file being created is a FIFO. The 0666 represents the permissions on the FIFO file (read and write permissions for everyone).
    // 0: The third argument is used for special files like block/character devices, but it's set to 0 for FIFOs.
    mknod("myfifo",S_IFIFO|0666,0);

    printf("writing for reader process:\n\t");
    fd = open("myfifo",O_WRONLY); // O_WRONLY is used to open the file in write-only mode.


    /*
    write(fd, str, strlen(str)): This writes the contents of the string str (user input) into the FIFO file, using the file descriptor fd.
    strlen(str): This function returns the length of the string str, so the correct number of bytes is written.
    nbw: This variable stores the number of bytes successfully written to the file
    */
    while(gets(str)) {
        nbw = write(fd,str,strlen(str));
        printf("writer process write %d bytes: %s\n", nbw,str);
    }

    return 0;
}

