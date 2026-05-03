#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    struct stat s;

    umask(022);
    int fd = open("f1.txt", O_CREAT | O_WRONLY, 0777);
    close(fd);

    stat("f1.txt", &s);
    printf("%o\n", s.st_mode & 0777); // after umask

    chmod("f1.txt", 0600);

    stat("f1.txt", &s);
    printf("%o\n", s.st_mode & 0777); // after chmod
}