#include<stdio.h>
void main()
{
    int arr[] = {10, 30, 56, -6, 1, 0};
    int *p, *q;
    p = arr;
    printf("%p %p\n", (void*)arr, (void*)p);
    printf("%d\n", *(++p));
    printf("%p %p\n", (void*)arr, (void*)p);
}
