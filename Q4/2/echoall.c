#include <stdio.h>

int main(int c, char *v[])
{
    for (int i = 0; i < c; i++)
    {
        printf("%s\n", v[i]);
    }
}

// compile this as cc echoall.c -o echoall
// make sure to chmod +x interp