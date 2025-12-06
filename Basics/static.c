#include<stdio.h>

static char ch;

void display();

void main()
{
    display();
    display();
    //printf("x = %d\n",x); error.
    //printf("c = %c\n",ch);
}

void display()
{
    int x = 0;
    //static int x;
    //auto int x;
    //auto int x;
    static int y = 10;
    x = x + 10;
    printf("x = %d\n",x); // 10
    printf("y = %d\n",--y); // 9
}
// it is going to retain its previous value.
// Using only auto int x is printing 10 and 20 by coincidence.
// SCOPE and LIFETIME are DIFFERENT
