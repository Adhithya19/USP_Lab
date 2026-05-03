#include <unistd.h>
#include <sys/wait.h>

int main()
{
    if (fork() == 0)
    {
        execl("./add", "add", "10", "20", NULL);
    }
    else
    {
        wait(NULL); // wait for child
    }
}