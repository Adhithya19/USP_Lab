#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int c, char *v[])
{
    int fd = open(v[1], 2); // open file
    struct flock f = {F_WRLCK, SEEK_END, -100, 100};
    // last 100 bytes region

    fcntl(fd, F_GETLK, &f); // check if region is locked

    if (f.l_type != F_UNLCK)     // if locked
        printf("%d\n", f.l_pid); // print PID of locker
    else
    {
        f.l_type = F_WRLCK;
        fcntl(fd, F_SETLK, &f); // lock region

        lseek(fd, -50, 2); // go to last 50 bytes
        char b[50];
        read(fd, b, 50); // read 50 bytes
        write(1, b, 50); // print to screen

        f.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &f); // unlock region
    }
}