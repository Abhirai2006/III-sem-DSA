#include<stdio.h>

int natural(int);

void main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("%d",natural(n));
}

int natural(int x)
{
    int s = 0;
    if(x == 1)
        return x;

    s = x + natural(x - 1);
    return s;
}
