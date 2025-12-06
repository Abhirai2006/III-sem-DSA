#include<stdio.h>
void main()
{
    int a = 10;
    int *ptr = &a;
    printf("a = %d %d\n",a,*ptr);
    printf("%x %x\n",&a,ptr);

    int c = (10,20,30,40);
    printf("%d",c);
}
