#include<stdio.h>

int a = 50; int b = 8;// Global scope

void add();
void fun();

void main()
{
    int x = 100;
    {
        printf("%d\n",a); // Block 1 // 20
    }

    {
        int x = 100;
        printf("%d\n",a); // Block 2  10
    }
    printf("%d\n",a);
    printf("%d\n",b);

    add();
    fun();
}


void add()
{
    int a = 30; int b = 90;
    printf("%d %d\n",a,b);
}

void fun()
{
    int print = 10;
    printf("%d\n",print);
}

