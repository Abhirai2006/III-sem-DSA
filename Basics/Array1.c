#include<stdio.h>
#include<stdlib.h>
#define N 100

int arr[100];
int size = 0;

void insertatthebeginning();
void insertataposition();
void insertattheend();
void deleteatthebeginning();
void deleteataposition();
void deleteattheend();
void display();
void lengthofthearray();

void main()
{
    int choice;
    while(1)
    {
        printf("1). Insert an element in the beginning.\n");
        printf("2). Insert an element at a particular position.\n");
        printf("3). Insert an element in the end.\n");
        printf("4). Delete an element in the beginning.\n");
        printf("5). Delete an element at a particular position.\n");
        printf("6). Delete an element in the end.\n");
        printf("7). Display the array.\n");
        printf("8). Length of the Array.\n");
        printf("9). Exit.\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insertatthebeginning();
            break;

        case 2:
            insertataposition();
            break;

        case 3:
            insertattheend();
            break;

        case 4:
            deleteatthebeginning();
            break;

        case 5:
            deleteataposition();
            break;

        case 6:
            deleteattheend();
            break;

        case 7:
            display();
            break;

        case 8:
            lengthofthearray();
            break;

        case 9:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid option. Try again.\n");
        }
    }
}

// My code
void insertatthebeginning()
{
    int count;
    printf("How many elements do you want to insert? ");
    scanf("%d", &count);

    if (size + count > N) // N is 100
    {
        printf("Not enough space to insert %d elements.\n", count);
        return;
    }

    int nums[count];
    for (int i = 0; i < count; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &nums[i]); // 4 and 5
    }

    for (int i = size - 1; i >= 0; i--)
    {
        arr[i + count] = arr[i];
    }

    for (int i = 0; i < count; i++)
    {
        arr[i] = nums[i];
    }

    size = size + count;
    printf("%d elements inserted at the beginning.\n", count);
}

void insertataposition()
{
    int num;
    printf("Enter the data you want to insert: ");
    scanf("%d",&num);

    if(size == N)
    {
        printf("Array is full.\n");
        return;
    }

    int position;
    printf("Enter the position where you want to insert(%d to %d): ",1,size+1);
    scanf("%d",&position);

    if(position < 1 || position > size + 1)
    {
        printf("Invalid position.\n");
        return;
    }

    for(int i=size-1; i >= position-1; i--)
    {
        arr[i+1] = arr[i];
    }

    arr[position - 1] = num;
    size++;

    printf("%d has been inserted in the %d position.\n",num,position);
}

insertattheend()
{
    int num;
    printf("Enter the data you want to insert: ");
    scanf("%d",&num);

    if(size == N)
    {
        printf("Array is full.\n");
        return;
    }
    size++;
    printf("%d inserted at the end.\n",num);
}


// My function
void deleteatthebeginning()
{
    if(size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    else
    {
        for(int i=1; i<size; i++)
        {
            arr[i-1] = arr[i];
        }
    }
    size--;
    printf("The first element has been deleted from the beginning.\n");
}

void deleteataposition()
{
    if(size == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    int position;
    printf("Enter the position from where you want to delete the element from: ");
    scanf("%d",&position);

    if(position < 1 || position > size)
    {
        printf("Invalid position.\n");
        return;
    }

    for(int i=position-1; i<size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;
    printf("The element has been deleted from the %d position.\n",position);
}

void deleteattheend()
{
    if(size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    size--;
    printf("The last node has been deleted from the list.\n");
}

void display()
{
    if(size == 0)
    {
        printf("Array is empty. Nothing to delete.\n");
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

void lengthofthearray()
{
    printf("Length of the array is %d.\n",size);
}

