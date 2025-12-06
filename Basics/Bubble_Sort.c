#include<stdio.h>
void main()
{
    int n,temp,mid,count = 0;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];

    /** NOTE:- Enter the elements of the array in an unsorted manner. **/

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

    // BUBBLE SORT
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("The array after sorting is\n");

    for(int i=0; i<n; i++)
    {
        printf("The element at arr[%d] is: %d\n",i,arr[i]);
    }

    int element;
    printf("Enter the element you want to search in the array: ");
    scanf("%d",&element);


    // BINARY SEARCH

    int high = n - 1;
    int low = 0;

    while(low <= high)
    {
        mid = ((low + high)/2);

        if(arr[mid]  == element)
        {
            printf("Element %d is found at arr[%d]",element,mid);
            count++;
            return;
        }

        else if(arr[mid] < element)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    if(count == 0)
    {
        printf("%d is not there in the array arr.\n",element);
        return;
    }
}

