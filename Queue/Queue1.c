/** Circular queue implementation using arrays **/

#include<stdio.h>
#include<stdlib.h>
#define N 10

int front = -1;
int rear = -1;

int queue[N];

void enqueue();
void dequeue();
void display();
void peek();

void main()
{
    while(1)
    {
        int choice;

        printf("1). Enqueue\n");
        printf("2). Dequeue\n");
        printf("3). Display\n");
        printf("4). Peek\n");
        printf("5). Exit\n");

        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice.\n");

        }
    }
}

void enqueue()
{
    int x;
    printf("Enter the value of x: ");
    scanf("%d",&x);

    if((rear + 1) % N == front)
    {
        printf("The queue is full.\n");
        return;
    }

    else if(front == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }

    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }

    printf("Inserted %d\n", x);
}


void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    else if(front == rear)
    {
        printf("Deleted %d\n", queue[front]);
        // queue becomes empty
        front = rear = -1;
    }

    else
    {
        int ele = queue[front];
        front = (front + 1) % N;
        printf("The removed element is %d\n",ele);
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    else
    {
        printf("Queue: ");
        for(int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    else
    {
        printf("%d",queue[front]);
    }
}




