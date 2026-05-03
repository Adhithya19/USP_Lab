#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("file.txt", O_WRONLY | O_CREAT, 0644);

    int d1 = dup(fd);     // gets next free fd
    int d2 = dup2(fd, 6); // forces fd = 5

    printf("dup: %d\n", d1);
    printf("dup2: %d\n", d2);
}
