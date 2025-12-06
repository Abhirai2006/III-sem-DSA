#include<stdio.h>

int ackermann(int,int);

void main()
{
    int m,n;
    printf("Enter the values of m and n: ");
    scanf("%d %d",&m,&n);

    printf("%d",ackermann(m,n));
}


int ackermann(int m, int n)
{
    if(m == 0)
        return n + 1;
    else if(m > 0 && n == 0)
        return ackermann(m - 1, 1);
    else
        return ackermann(m - 1, ackermann(m, n - 1));
}
