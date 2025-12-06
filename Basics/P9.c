#include<stdio.h>
void hello();
void main()
{
    int a,b,c;
    printf("Enter the values for a, b and c:\n");
    scanf("%d %d %d",&a,&b,&c);
    if(a>=b)
        if(a>=c)
            printf("%d is greater than or equal to %d and %d.\n",a,b,c);
        else
            printf("%d is greater than or equal to %d and %d.\n",c,a,b);
    else
        if(b>=c)
            printf("%d is greater than or equal to %d and %d.\n",b,a,c);
        else
            printf("%d is greater than or equal to %d and %d.\n",c,a,b);
    hello();
}

void hello()
{
    printf("My name is Hello.\n");
}
