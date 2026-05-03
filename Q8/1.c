#include <stdio.h>
#include <sys/stat.h>

int main(int c, char *v[])
{
    struct stat s;
    stat(v[1], &s); // get file info

    if (S_ISREG(s.st_mode))
        printf("Regular\n");
    else if (S_ISDIR(s.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(s.st_mode))
        printf("Char device\n");
    else if (S_ISBLK(s.st_mode))
        printf("Block device\n");
    else if (S_ISFIFO(s.st_mode))
        printf("FIFO\n");
}