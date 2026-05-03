#include <unistd.h>
#include <sys/wait.h>

int main()
{
    if (fork() == 0)
    {
        char *env[] = {"USER=custom", "PATH=/tmp", NULL};
        execle("./echoall", "echoall", NULL, env); // child → custom env
    }
    else
    {
        wait(NULL);
        execl("./echoall", "echoall", NULL); // parent → default env
    }
}
// compile echoall.c with cc echoall.c -o echoall then compile this with cc main.c -o main