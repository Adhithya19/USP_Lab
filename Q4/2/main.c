#include <stdio.h>
#include <unistd.h>
int main()
{
    if (fork() == 0)
    {
        execl("./interp", "interp", "Hello", NULL);
    }
}