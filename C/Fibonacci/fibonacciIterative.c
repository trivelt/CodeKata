#include <stdio.h>

/*
Compute nth fibonacci number by iteration
*/
unsigned int fibonacci(unsigned int n)
{
    int i;
    unsigned int first = 0;
    unsigned int second = 1;

    if(n==0)
        return first;

    for(i=1; i<n; i++)
    {
        int tmp = second;
        second += first;
        first = tmp;
    }
    return second;
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
