#include<stdio.h>

// register int a = 30;

void main()
{
    register float a; // Try using only register int a;
    register int b;
    {
        register int a;
        printf("%d\n",a); // Garbage value
    }
    printf("%f\n",a);
}

