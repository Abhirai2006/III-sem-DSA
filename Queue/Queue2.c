#include<stdio.h>
#include<stdlib.h>
#define N 10

int front = -1;
int rear = -1;

int queue[N];

void enqueue();
void dequeue();
void display();

void main()
{
    while(1)
    {
        int choice;

        printf("1). Enqueue\n");
        printf("2). Dequeue\n");
        printf("3). Display\n");
        printf("4). Exit\n");

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
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice.\n");

        }
    }
}

void enqueue()
{
    if(rear == N - 1)
    {
        printf("The queue is full.\n");
        return;
    }

    int x;
    printf("Enter the value of x: ");
    scanf("%d",&x);

    if(front == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        return;
    }

    rear++;
    queue[rear] = x;
    printf("Inserted %d\n", x);
}


void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);

    if(front == rear)
    {
        // queue becomes empty
        front = rear = -1;
    }
    else
    {
        int ele = queue[front];
        front++;
        printf("The removed element is %d\n",ele);
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}






