// program for creating three child processes using ‘system’ system call.

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\nWatch out 'mkdir' below\n");
    system("mkdir a");
    printf("\nWatch out 'notepad' below\n");
    system("echo Hello from notepad > notepad_input.txt && notepad notepad_input.txt");
    printf("\nWatch out 'dir' below\n");
    system("dir");
    return 0;
}
