#include<stdio.h>

void main()
{
    int i = 1;

    int n;  // 10
    printf("Enter the value of n: ");
    scanf("%d",&n);

    while(n >= i)
    {
        printf("%d\n",i);
        n--;
    }
}
