// Program for creating a process using fork ()
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before fork\n");

    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process (PID: %d)\n", getpid());
    } else if (pid > 0) {
        printf("Parent process (PID: %d)\n", getpid());
        printf("Child process created with PID: %d\n", pid);
    } else {
        perror("Fork failed\n");
        return 1;
    }

    printf("After fork\n");

    return 0;
}