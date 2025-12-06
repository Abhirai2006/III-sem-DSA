#include<stdio.h>
#define MAX 100

void createarray(int arr[],int n);
void display(int arr[],int n);
int Indinsertion(int arr[],int n,int index,int element,int capacity);


void main()
{
    int n,index,element,arr[MAX];
    printf("Enter n(used_size),index,element:");
    scanf("%d %d %d",&n,&index,&element);
    createarray(arr,n);
    display(arr,n);
    Indinsertion(arr,n,index,element,MAX);
    n = n+1;
    display(arr,n);
    //printf("\a");
}

void createarray(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",&arr[i]);
    }
}

void display(int arr[],int n)
{
    printf("The elements of the array are...\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}

int Indinsertion(int arr[],int n,int index,int element,int capacity)
{
    if(n>=capacity)
        return -1;
    for(int i=n-1; i>=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return -1;
}







