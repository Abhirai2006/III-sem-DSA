#include<stdio.h>
void main()
{
    int a = 10;
    int *ptr = &a;
    printf("a = %x %x\n",&a,ptr);
    printf("a = %d %d",a,*ptr);
}
