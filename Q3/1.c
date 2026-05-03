#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
// NOTE: USAGE IS "./a.out . ". is for current directory"
int main(int c, char *v[])
{
    DIR *d = opendir(v[1]);
    struct dirent *e;
    struct stat s;
    char p[200];

    while ((e = readdir(d)))
    {
        sprintf(p, "%s/%s", v[1], e->d_name);
        stat(p, &s);
        if (s.st_size == 0)
            remove(p);
    }
}

/*
d → opened directory stream (folder handle)
e → current file entry being read
p → full path of current file (one at a time)
s → metadata of current file (size, etc.)*/