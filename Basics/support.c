#include<stdio.h>
extern int x;

void display()
{
    x = x + 50;
    printf("This is support class.\n");
    printf("x = %d\n",x);
}
