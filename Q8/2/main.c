#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());
        execl("./access", "access", "file.txt", NULL);
    }
    else
    {
        printf("Parent PID: %d\n", getpid());
        wait(NULL);
        printf("Child finished\n");
    }
}