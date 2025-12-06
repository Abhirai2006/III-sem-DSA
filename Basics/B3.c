#include<stdio.h>

void main()
{
    int a = 10, b = 5,c;
    int result;
    printf("%d\n", a || 0);

    result = a > b && b != 10 && b < 11 && a > 5 && printf("ABC\n") && scanf("%d",&c) && printf("%d\n",c);
    printf("%d\n",result);
}
