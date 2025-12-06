#include<stdio.h>
void main()
{
    int arr[] = {10,20,30,40};
    int *ptr = arr;
    for(int i=0; i<4; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n%x %x %x\n",ptr,arr,&arr[0]);


    for(int i=0; i<4; i++)
    {
        printf("%d ",*(ptr + i));
    }
}
