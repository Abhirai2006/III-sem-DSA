#include<stdio.h>
void main()
{
    int diff;
    int arr[] = {10, 30, 56, -6, 1, 0};
    int *p, *q;
    p = arr;       // p → &arr[0]
    q = &arr[4];   // q → &arr[3]
    diff = q - p;  // 3
    printf("%d", diff);
}
