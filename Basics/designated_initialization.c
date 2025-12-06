#include<stdio.h>
#include<stdlib.h>
struct demo
{
    int a;
    float b;
    char c;
};

void main()
{
    struct demo d = {.c = 'a', .a = 10, .b = 6.89f};
    printf("%c %d %f",d.c,d.a,d.b);
}
