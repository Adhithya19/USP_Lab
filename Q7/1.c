#include <stdio.h>
#include <setjmp.h>

jmp_buf j;

int main()
{
    int a = 1;
    register int b = 2;
    volatile int c = 3;

    if (setjmp(j))
    {
        printf("%d %d %d\n", a, b, c); // after longjmp
    }
    else
    {
        a = 10;
        b = 20;
        c = 30;
        longjmp(j, 1); // jump back
    }
}