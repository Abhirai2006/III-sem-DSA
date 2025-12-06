#include<stdio.h>

int count = 0;

void main()
{
    int n,element;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter the %d element at index arr[%d]: ",i+1,i);
        scanf("%d",&arr[i]);
    }

    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("The element at arr[%d] is: %d\n",i,arr[i]);
    }

    printf("\n");

    printf("Enter the element you want to search in the array: ");
    scanf("%d",&element);

    for(int i=0; i<n; i++)
    {
        if(arr[i] == element)
        {
            printf("Element %d is found at arr[%d]",element,i);
            count++;
            return;
        }
    }
    if(count == 0)
    {
        printf("%d is not there in the array arr.\n",element);
        return;
    }
}
