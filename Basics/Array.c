#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[100],n,i,pos,num;

void create();
void display();
void insert();
void delete();

void main()
{
    int ch;
    while(1)
    {
        printf("--------------------------------------");
        printf("\n 1. Create an array");
        printf("\n 2. Display an array");
        printf("\n 3. Insert an element into an array");
        printf("\n 4. Delete element");
        printf("\n 5. Exit");
        printf("\n ------------------------------------");
        printf("\n Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete();
            break;
        case 5:
            exit(0);
        default:
            printf("Invaid option\n");
            break;
        }
        getch();
    }
}
void create()
{
    printf("Enter the size of an array\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
}
void display()
{
    printf("Array elements are\n ");
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
}
void insert()
{
    printf(" Enter number to be inserted\n");
    scanf("%d",&num);
    printf("Enter the postion to insert\n");
    scanf("%d",&pos);
    for(i=n-1; i>=pos-1; i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=num;
    n++ ;
}
void delete()
{
    int item;
    printf("Enter the element position ");
    scanf("%d",&pos);
    item=a[pos-1];
    for(i=pos-1; i<n-1; i++)
    {
        a[i]=a[i+1];
    }
    n--;
    printf("Deleted element is %d ",item);
}
