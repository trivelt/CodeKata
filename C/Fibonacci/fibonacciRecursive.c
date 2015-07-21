#include <stdio.h>

/*
Compute nth fibonacci number by recursion
*/
int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibonacci(n-2) + fibonacci(n-1);
}

int main(int argc, char** argv)
{
    int i;

    for(i=0;i<16;i++)
    {
        printf("%d Fibonacci number = %d\n", i, fibonacci(i));
    }
    return 0;
}
