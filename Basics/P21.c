#include<stdio.h>
void main()
{
    const int a = 10;
    const int *ptr = &a;
    printf("a = %d , %d",a,*ptr);
    // *ptr = 20; // error
}
