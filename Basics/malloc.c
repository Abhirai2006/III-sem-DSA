#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *ptr = (int*)calloc(3 , sizeof(int));
    int *ptr1 = (int*)malloc(3 * sizeof(int));

    for(int i=0; i<3; i++)
    {
        printf("%d ",*(ptr + i));
    }

    printf("\n");
    for(int i=0; i<3; i++)
    {
        printf("%d ",*(ptr1 + i));
    }
}
