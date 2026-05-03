#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int c, char *v[])
{
    int fd = open(v[1], 0);
    char ch;
    int i = lseek(fd, 0, 2); // 2 means SEEK_END

    while (i--)
    {
        lseek(fd, i, 0); // 0 means SEEK_SET, so we move to the position i from the start of the file
        read(fd, &ch, 1);
        printf("%c", ch);
    }
}