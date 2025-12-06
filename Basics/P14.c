#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,*ptr;
    printf("Enter the size of n:");
    scanf("%d",&n);
    ptr = (int*)malloc(n * sizeof(int));
    if(ptr == NULL)
        printf("Memory allocation failed.\n");
    else
        printf("Memory allocated successfully and the address is %p\n",(void*)ptr);
    for(int i=0; i<n; i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",(ptr+i));
    }
    for(int i=0; i<n; i++)
    {
        printf("The element at %d location is %d\n",i+1,*(ptr+i));
    }

    free(ptr);

}
