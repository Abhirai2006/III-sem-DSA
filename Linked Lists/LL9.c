#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data1;
    float data2;
    struct node *next;
};

void ibegin();
void iend();
void ipos();
void dbegin();
void dend();
void dpos();
void length();
void display();

struct node *head = NULL;
struct node *new_node = NULL;
struct node *temp = NULL;

int count = 0;

void main()
{
    while(1)
    {
        int choice;

        printf("1). Insert begin.\n");
        printf("2). Insert end.\n");
        printf("3). Insert position.\n");
        printf("4). Delete begin.\n");
        printf("5). Delete end.\n");
        printf("6). Delete position.\n");
        printf("7). Length.\n");
        printf("8). Display.\n");
        printf("9). Exit.\n");

        printf("Enter you choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            ibegin();
            break;

        case 2:
            iend();
            break;

        case 3:
            ipos();
            break;

        case 4:
            display();
            break;

        case 9:
            printf("Exiting Program.\n");
            return;

        default:
            printf("Invalid choice.\n");
            return;
        }
    }
}


void ibegin()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("Enter the data: ");
    scanf("%d %f",&new_node->data1, &new_node->data2);

    new_node->next = head;
    head = new_node;

    count++;
    printf("%d and %.2f have been successfully added in the 1st position.\n",new_node->data1, new_node->data2);
}


void iend()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("Enter the data: ");
    scanf("%d %f",&new_node->data1, &new_node->data2);

    new_node->next = NULL;

    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;

    count++;
    printf("%d and %.2f have been successfully added in the last position.\n",new_node->data1, new_node->data2);
}


void ipos()
{
    int position;
    printf("Enter the position where you want to insert: ");
    scanf("%d",&position);

    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("Enter the data: ");
    scanf("%d %f",&new_node->data1, &new_node->data2);

    if(position < 1 || position > count + 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if(position == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {

        temp = head;
        for(int i=1; i<position-1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    count++;
    printf("Node has been successfully inserted at %d position\n",position);
}


void display()
{
    if(head == NULL)
    {
        printf("The List is empty.\n");
        return 0;
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d and %.2f -> ",temp->data1, temp->data2);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
