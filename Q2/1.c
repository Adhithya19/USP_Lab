#include <stdio.h>
#include <sys/stat.h>

int main(int c, char *v[])
{
    struct stat s;
    stat(v[1], &s);

    printf("Size: %ld\n", s.st_size);
    printf("Inode: %ld\n", s.st_ino);
    printf("Mode: %o\n", s.st_mode);
    printf("Links: %ld\n", s.st_nlink);
    printf("UID: %d\n", s.st_uid);
}