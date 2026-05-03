#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int c, char *v[])
{
    if (c < 2)
        return 1;

    if (fork() == 0)
    {
        execl("/bin/sh", "sh", "-c", v[1], NULL); // here NULL is used to indicate the end of the argument list for execl
    }
    else
    {
        wait(NULL);
    }
}