#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int fd = open("hello.txt", O_RDONLY);
    char ch;

    if (fork() == 0)
    {
        read(fd, &ch, 1);
        printf("Child: %c\n", ch);
        fflush(stdout);
    }
    else
    {
        wait(NULL); // ensure child reads first
        read(fd, &ch, 1);
        printf("Parent: %c\n", ch);
    }
}