#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    printf("Caught SIGINT\n");

    signal(SIGINT, SIG_DFL); // reset to default
}

int main()
{
    struct sigaction sa;

    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);

    while (1)
        ; // wait for Ctrl+C
}