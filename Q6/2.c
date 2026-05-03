#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int c, char *v[])
{
    int fd = open(v[1], 2);
    struct flock f = {F_WRLCK, SEEK_END, -100, 100};

    fcntl(fd, F_GETLK, &f);

    if (f.l_type != F_UNLCK)
        printf("%d\n", f.l_pid);
    else
    {
        f.l_type = F_WRLCK;
        fcntl(fd, F_SETLK, &f);
        lseek(fd, -50, 2);
        char b[50];
        read(fd, b, 50);
        write(1, b, 50);
        f.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &f);
    }
}