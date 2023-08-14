// Write a program that creates three processes using fork() system call.

#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid, pid1, pid2, pid3;
    int ppid1, ppid2, ppid3;
    int p1, p2, p3;
    pid = getpid();
    printf("\n Parent's pid=%d\n", pid);
    p1 = fork();
    if (p1 == 0)
    {
        pid1 = getpid();
        printf("\n Child 1's pid=%d\n", pid1);
        ppid1 = getppid();
        printf("\n Child 1's parent's pid=%d\n", ppid1);
        p2 = fork();

        if (p2 == 0)
        {
            pid2 = getpid();
            printf("\n Child 2's pid=%d\n", pid2);
            ppid2 = getppid();
            printf("\n Child 2's parent's pid=%d\n", ppid2);
            p3 = fork();
            if (p3 == 0)
            {
                pid3 = getpid();
                printf("\n Child 3's pid=%d\n", pid3);
                ppid3 = getppid();
                printf("\n Child 3's parent's pid=%d\n", ppid3);
            }
        }
    }
    return 0;
}
