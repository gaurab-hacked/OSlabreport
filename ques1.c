// program for printing process id

#include <stdio.h>
#include <unistd.h>

int main() {
    int pid, ppid;
    pid = getpid();
    printf("The process ID is %d\n", pid);
    return 0;
}
