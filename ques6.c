// program demonstrates the use of strict alternation method to achieve mutual exclusion for critical region problem.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread1f(void *arg);
void *thread2f(void *arg);

int turn = 1; // Indicates whose turn it is

int main()
{
    pthread_t thid1;
    pthread_t thid2;

    pthread_create(&thid1, NULL, &thread1f, NULL);
    pthread_create(&thid2, NULL, &thread2f, NULL);

    pthread_join(thid1, NULL);
    pthread_join(thid2, NULL);

    return 0;
}

void *thread1f(void *arg)
{
    int a = 0;
    while (a++ < 20)
    {
        while (turn != 1)
            ; // Busy wait until it's thread 1's turn
        fputc('b', stderr);
        turn = 0; // Give the turn to thread 2
    }
}

void *thread2f(void *arg)
{
    int b = 0;
    while (b++ < 20)
    {
        while (turn != 0)
            ; // Busy wait until it's thread 2's turn
        fputc('a', stderr);
        turn = 1; // Give the turn back to thread 1
    }
}
