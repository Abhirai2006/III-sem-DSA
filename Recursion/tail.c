#include<stdio.h>

void print(int);

void main()
{
    print(10);
}

void print(int a)
{
    if(a < 1)
        return;
    else
    {
        printf("%d ",a);
        print(a / 2);
    }
}
