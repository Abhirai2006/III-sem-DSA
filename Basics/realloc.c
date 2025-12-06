#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n1,n2,*ptr,*ptr1;
    printf("Enter the values for n1 and n2:");
    scanf("%d %d",&n1,&n2);
    ptr = (int*)malloc(n1 * sizeof(int));
    for(int i=0; i<n1; i++)
        scanf("%d",(ptr+i));
    for(int i=0; i<n1; i++)
        printf("%d ",*(ptr+i));

    ptr1 = (int*)realloc(ptr, n2 * sizeof(int));

    for(int i=n1; i<n2; i++)
        scanf("%d",(ptr1+i));

    for(int i=0; i<n2; i++)
        printf("\n%d ",*(ptr+i));

    printf("\n%x %x",ptr ,ptr);
    free(ptr1);
}
