#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int c, char *v[])
{
    int fd = open(v[1], 2), n = atoi(v[2]);
    char b[100];
    read(fd, b, n);
    lseek(fd, 0, 2);
    dup2(fd, 1);
    write(1, b, n);
}