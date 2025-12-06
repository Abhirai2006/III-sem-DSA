#include <stdio.h>

void display();

void main()
{
    display();
    display();
    display();
}

void display()
{
    static int x = 5;
    int y = 5;
    static int z = 12;

    x++;
    y++;

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n",z++);
    printf("%d",z);
}

