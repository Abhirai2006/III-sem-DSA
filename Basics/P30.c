#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)for packing
struct demo
{
    char a;
    int b;
    double c;
}d;
void main()
{
    printf("%d",sizeof(d));
}
