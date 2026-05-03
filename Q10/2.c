#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid = fork();

    if (pid == 0)
    {
        printf("Child 1 PID: %d\n", getpid());
        exit(5);
    }
    else
    {
        int status;

        wait(&status);
        if (WIFEXITED(status))
            printf("Child 1 exited with %d\n", WEXITSTATUS(status));

        printf("wait done\n");

        pid = fork();

        if (pid == 0)
            exit(10);

        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            printf("Child 2 exited with %d\n", WEXITSTATUS(status));

        printf("waitpid done\n");
    }
}