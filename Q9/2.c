#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int c, char *v[])
{
    int fd = open(v[1], O_RDONLY);
    char b[21];

    read(fd, b, 20);
    b[20] = '\0'; // first 20 chars
    printf("First 20: %s\n", b);

    lseek(fd, 10, SEEK_SET); // from beginning
    read(fd, b, 20);
    b[20] = '\0';
    printf("From 10th byte: %s\n", b);

    lseek(fd, 10, SEEK_CUR); // 10 ahead from current
    read(fd, b, 20);
    b[20] = '\0';
    printf("10 ahead: %s\n", b);

    int size = lseek(fd, 0, SEEK_END); // file size
    printf("Size: %d\n", size);
}