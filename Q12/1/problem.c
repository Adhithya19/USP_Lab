#include <unistd.h>

int main()
{
    if (fork() == 0)
    {
        _exit(0); // child exits immediately
    }
    sleep(10); // parent does NOT wait → zombie exists
}