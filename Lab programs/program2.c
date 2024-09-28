// Parent Process Computes the SUM OF EVEN
// and Child Process Computes the sum of ODD
// NUMBERS using fork

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {
    int start = 1, end = 10;
    pid_t pid = fork();

    if(pid < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if(pid == 0) {
        int sum_odd = 0;
        for(int i=start ; i<=end ; i++) {
            if(i % 2 != 0) {
                sum_odd += i;
            }
        }
        printf("child process: Sum of odd numbers = %d\n",sum_odd);
    } else {
        int sum_even = 0;
        for(int i=start ; i<=end ; i++) {
            if(i % 2 == 0) {
                sum_even += i;
            }
        }
        wait(NULL);
        printf("parent process: sum of even numbers = %d\n",sum_even);
    }

    return 0;
}