#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int c, char *v[])
{
    DIR *d = opendir(v[1]);
    struct dirent *e;
    struct stat s;
    char p[200];

    printf("ino\t size\t mode\t links\t name\n");

    while ((e = readdir(d)))
    {
        sprintf(p, "%s/%s", v[1], e->d_name);
        stat(p, &s);

        printf("%ld %ld %o %ld %s\n",
               s.st_ino, s.st_size, s.st_mode, s.st_nlink, e->d_name);
    }
}