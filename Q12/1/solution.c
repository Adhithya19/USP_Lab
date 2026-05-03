#include <unistd.h>
#include <sys/wait.h>

int main()
{
    if (fork() == 0)
    {
        _exit(0);
    }
    wait(NULL); // parent collects child → no zombie
}