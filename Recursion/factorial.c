#include<stdio.h>

int factorial(int);

void main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    /**
    int x = factorial(n);
    printf("%d",x); **/

    printf("The factorial of %d is : %d",n,factorial(n));
}

int factorial(int n)
{
    if(n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
