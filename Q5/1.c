#include <stdio.h>
#include <sys/stat.h>
#include <utime.h>

int main(int c, char *v[])
{
    struct stat s;
    struct utimbuf t;

    stat(v[1], &s); // get time from source file

    t.actime = s.st_atime;  // access time
    t.modtime = s.st_mtime; // modification time

    utime(v[2], &t); // apply to destination file
}