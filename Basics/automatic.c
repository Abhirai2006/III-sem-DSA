#include<stdio.h>

// auto int a = 30;

void main()
{
    auto int a; // Try using only auto int a;
    {
        auto int a;
        printf("%d\n",a); // Garbage value
    }
    printf("%d\n",a);
}
