#include<stdio.h>
void main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",&arr[i]);
    }
    int *ptr = arr; // int *ptr = &arr[0];
    printf("%d\n",*ptr);
    ptr++;
    printf("%d\n",*ptr);
    ptr = ptr+1;
    printf("%d\n",*ptr);
    ptr = ptr + 20;
    printf("%d\n",*ptr);
}
