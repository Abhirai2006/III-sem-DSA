#include<stdio.h>
#include<stdlib.h>
#define N 100

struct node
{
    int data;
    char *name;
    struct node *next;
    struct node *prev;
};
int count = 0;

struct node *new_node = NULL;
struct node *head = NULL;
struct node *temp = NULL;

void display();
void length();

void insertbegin();
void insertend();
void insertatposition();

void deletebegin();
void deleteend();
void deletepos();

void main()
{
    int choice;
    while(1)
    {
        printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
        printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("1). Display the List.\n");
        printf("2). Length of the List.\n");
        printf("3). Insert at the beginning of the List.\n");
        printf("4). Insert at the end of the List.\n");
        printf("5). Insert at a particular position of the List.\n");
        printf("6). Delete at the beginning of the List.\n");
        printf("7). Delete at the end of the List.\n");
        printf("8). Delete at a particular position of the List.\n");
        printf("9). Exit.\n");
        printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
        printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            display();
            break;

        case 2:
            length();
            break;

        case 3:
            insertbegin();
            break;

        case 4:
            insertend();
            break;

        case 5:
            insertatposition();
            break;

        case 6:
            deletebegin();
            break;

        case 7:
            deleteend();
            break;

        case 8:
            deletepos();
            break;

        case 9:
            exit(0);

        default:
            printf("Invalid option.\n");
            break;
        }

    }
}

void insertbegin()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->name = (char*)malloc(N * sizeof(char));
    if(new_node->name == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the data for node %d: ",1);
    scanf("%d %99s", &new_node->data, new_node->name);


    new_node->next = head;
    head = new_node;
    count++;
}

void insertend()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->name = (char*)malloc(N * sizeof(char));
    if(new_node->name == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the data for node %d: ", count + 1);
    scanf("%d %99s", &new_node->data, new_node->name);


    new_node->next = NULL;

    if(head == NULL)
        head = temp = new_node;
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        temp = temp->next;
    }
    count++;
}

void insertatposition()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos < 1 || pos > count + 1)
    {
        printf("Invalid position.\n");
        return;
    }

    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->name = (char*)malloc(N * sizeof(char));
    if(new_node->name == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the data for node %d: ", pos);
    scanf("%d %99s", &new_node->data, new_node->name);

    new_node->next = NULL;

    if (pos == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    printf("Node has been successfully inserted at %d position.\n",pos);
    count++;
}

void deletebegin()
{
    if(head == NULL)
    {
        printf("The list is empty, it has no nodes to delete.\n");
        return;
    }

    temp = head;
    head = temp ->next;
    free(temp);

    count--;

}

void deleteend()
{
    struct node *prev = NULL;
    if(head == NULL)
    {
        printf("The list is empty, it has no nodes to delete.\n");
        return;
    }

    if(head ->next == NULL)
    {
        temp = head;
        free(temp);
        head = NULL;
    }
    else
    {
        temp = head;
        while(temp ->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev ->next = temp ->next;
        free(temp);
    }
    count--;
}

void deletepos()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);

    struct node *prev = NULL;

    if(pos < 1 || pos > count)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        temp = head;
        for (int i = 1; i < pos ; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }

}

void display()
{
    temp = head;
    if(temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d %s -> ",temp->data,temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

void length()
{
    if(count == 0)
        printf("The list has no nodes so the length is %d\n",count);
    else
        printf("The number of nodes in the list are: %d\n",count);
}

