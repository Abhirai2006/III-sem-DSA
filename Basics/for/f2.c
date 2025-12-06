#include<stdio.h>

void main()
{
    int n = 5;

    for(int i = 1; i <= n; i++)
    {
        if(i == 3)
            break;
            continue;

        printf("%d ",i);
    }

}
