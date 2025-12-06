#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n = 5,*ptr,*ptr1;
    ptr = (int*)malloc(n * sizeof(int));
    ptr1 = (int*)calloc(n, sizeof(int));
    for(int i=0; i<5; i++)
    {
        printf("%d ",*(ptr+i));
    }
    printf("\n");
    for(int i=0; i<5; i++)
    {
        printf("%d ",*(ptr1+i));
    }
    free(ptr);
    free(ptr1);
}
