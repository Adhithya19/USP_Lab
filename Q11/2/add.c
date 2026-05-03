#include <stdio.h>
#include <stdlib.h>

int main(int c, char *v[])
{
    int a = atoi(v[1]);
    int b = atoi(v[2]);
    printf("Sum: %d\n", a + b);
}