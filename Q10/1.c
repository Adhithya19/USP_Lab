#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    if (fork())
        exit(0);
    setsid();
    if (fork())
        exit(0);

    chdir("/");
    close(0);
    close(1);
    close(2);

    open("/dev/null", O_RDWR);
    dup(0);
    dup(0);

    while (1)
    {
        int fd = open("/tmp/daemon.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
        write(fd, "Daemon is running\n", 19);
        close(fd);
        sleep(5);
    }
}