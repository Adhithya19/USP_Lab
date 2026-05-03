#include <stdio.h>
#include <unistd.h>

int main(int c, char *v[])
{
    if (access(v[1], F_OK) == 0)
        printf("File exists\n");
    else
        printf("File does not exist\n");
}