#include<stdio.h>
void main()
{
    int a = 10, b = 20, *p, *q;
    p = &a;
    q = &b;
    *q = *p;
    printf("%d %d %d\n",a,*p,*q);

    int a1 = 100, b1 = 200, *p1, *q1;
    p1 = &a1;
    //q = &b;
    q1 = p1;
    printf("%d %d %d",a1,*p1,*q1);

}
