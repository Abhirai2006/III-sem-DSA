#include<stdio.h>
#include "helper.c"
extern int g;
extern int add();
void main()
{
    // printf("The sum is %d",add());
    int sum = add();
    printf("The sum is %d\n",sum);
    printf("G = %d\n",g);
}
