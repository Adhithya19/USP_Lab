#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int c, char *v[])
{
    int fd = open(v[1], 2); // open file (read+write)
    int n = atoi(v[2]);     // number of characters
    char b[100];

    read(fd, b, n); // read n chars from start

    lseek(fd, 0, SEEK_END); // move to end of file
    dup2(fd, 1);            // redirect stdout (1) → file

    write(1, b, n); // write to file (append)
}