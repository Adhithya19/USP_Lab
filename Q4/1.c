#include <stdio.h>
#include <unistd.h>

int main()
{
    char file[50], hard[50], soft[50];

    scanf("%s %s %s", file, hard, soft);

    link(file, hard);    // hard link
    symlink(file, soft); // soft link
}