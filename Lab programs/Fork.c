// If you just have a series of N fork statements one
// after the other, then the total number of
// processes formed are 2
// N-1.

#include<stdio.h>
#include<unistd.h>

int main() {
    fork();
    printf("creating fork process 1\n");
    fork();
    printf("creating fork process 2\n");
    fork();
    printf("creating fork process 3\n");

    return 0;
}
/*

OUTPUT

creating fork process 1
creating fork process 2
creating fork process 3
creating fork process 1
creating fork process 2
creating fork process 3
creating fork process 1
creating fork process 2
creating fork process 3
creating fork process 1
creating fork process 2
creating fork process 3
creating fork process 1
creating fork process 2
creating fork process 3
creating fork process 1
creating fork process 2
creating fork process 3
creating fork process 1
creating fork process 2
creating fork process 3
creating fork process 1
creating fork process 2
creating fork process 3


*/






