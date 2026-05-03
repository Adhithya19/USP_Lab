#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int c, char *v[])
{
    if (c < 3)
    {
        printf("Usage: src dest\n");
        return 1;
    }

    int f1 = open(v[1], 0); // source
    if (f1 < 0)
    {
        perror("open src");
        return 1;
    }

    int f2 = open(v[2], 1 | 64, 0666); // dest (create)
    if (f2 < 0)
    {
        perror("open dest");
        return 1;
    }

    char b[100];
    int n;

    while ((n = read(f1, b, 100)) > 0)
    {
        if (write(f2, b, n) != n)
        {
            perror("write");
            return 1;
        }
    }

    if (n < 0)
        perror("read");
}