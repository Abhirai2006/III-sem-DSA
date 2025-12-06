#include<stdio.h>

void main()
{
    int size;
    scanf("%d",&size);

    int arr[5] = {10,20,30,40,50};

    for(int i = 0 ; i < size; i++)
        printf("%d\t",&arr[i]);
}

