#include<stdio.h>

int gcd(int,int);

void main()
{
    int a,b;
    printf("Enter the values of a and b: ");
    scanf("%d %d",&a,&b);

    int result = gcd(a,b);
    printf("The GCD of %d and %d is %d",a,b,result);
}

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    else if(b == 0)
        return a;
    else
        gcd(b, a%b);
}
