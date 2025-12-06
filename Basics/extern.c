#include<stdio.h>

void fun1();
void fun2();

// int x = 10;

void main()
{
    int x;
    printf("x = %d\n",x);  // 10
    fun1();
    fun2();
}

void fun1()
{
    int x = 1;
    x = x + 5;
    printf("x = %d\n",x);
}

void fun2()
{
    int y = 4;
    y++;
    printf("y = %d\n",y);
}

 int x = 10;

