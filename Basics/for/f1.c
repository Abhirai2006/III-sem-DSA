#include<stdio.h>

void main()
{
    for(int i = 1, j = 5, k = 10; i <= 5, j >= 1, k >= 1; i++, j--, k--)
    {
        printf("%d ",i);
        printf("\n");
        printf("%d ",j);
        printf("\n");
        printf("%d ",k);
    }
}
