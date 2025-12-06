#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
struct stack *new_node = NULL;
struct stack *temp = NULL;

void push(int);
void pop();
void display();
void peek();

void main()
{
    int choice;
    while(1)
    {
        printf("1). Push\n");
        printf("2). Pop\n");
        printf("3). Display\n");
        printf("4). Peek\n");
        printf("5). Exit\n");

        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
        {
            int x;
            printf("Enter the value of x: ");
            scanf("%d",&x);
            push(x);
            break;
        }

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            printf("Exiting Program.\n");
            return;

        default:
            printf("Invalid choice.\n");
            return;
        }
    }
}


void push(int x)
{
    new_node = (struct stack*)malloc(sizeof(struct stack));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data = x;
    new_node->next = top;
    top = new_node;
}


void pop()
{
    temp = top;
    if(top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    top = top->next;
    free(temp);
}


void display()
{
    if(top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    temp = top;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void peek()
{
    if(top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    temp = top;
    printf("%d -> \n",temp->data);
}
