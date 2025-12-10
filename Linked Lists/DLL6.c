/** A menu driven approach for a Doubly Linked List **/

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
struct node *tail = NULL;

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

    new_node->prev = NULL;
    new_node->next = NULL;

    if(head == NULL)
        head = tail = new_node;
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    count++;
    printf("Node has been successfully inserted onto the list in the beginning of the list.\n");
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

    new_node->prev = NULL;
    new_node->next = NULL;

    if(head == NULL)
        head = tail = new_node;
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    count++;
    printf("Node has been successfully inserted onto the list at the end of the list.\n");
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

    if(pos == 1)
    {
        insertbegin();
        return;
    }

    if(pos == count + 1)
    {
        insertend();
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

    new_node->prev = NULL;
    new_node->next = NULL;


    temp = head;
    for(int i = 1; i < pos - 1; i++)
        temp = temp->next;

    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;

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
    else if(head ->next == NULL)
    {
        temp = head;
        head = NULL;
        free(temp);
    }
    else
    {
        temp = head;
        head = head ->next;
        head ->prev = NULL;
        free(temp);
    }
    count--;
    printf("A node has been successfully deleted from the front of the list.\n");
}

void deleteend()
{
    if(head == NULL)
    {
        printf("The list is empty, it has no nodes to delete.\n");
        return;
    }

    else if(head ->next == NULL)
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
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    count--;
    printf("A node has been successfully deleted from the end of the list.\n");
}

void deletepos()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);

    if(pos < 1 || pos > count)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        deletebegin();
        return;
    }
    else if (pos == count)
    {
        deleteend();
        return;
    }
    else
    {

        temp = head;
        for (int i = 1; i < pos ; i++)
        {
            temp = temp->next;
        }
        temp ->prev ->next = temp ->next;
        temp ->next ->prev = temp ->prev;
        free(temp);
    }
    count--;
    printf("A node has been successfully deleted from %d position.\n",pos);

}

void display()
{
    temp = head;
    if(temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    printf("NULL");
    while(temp != NULL)
    {
        printf(" <- %d %s -> ",temp->data,temp->name);
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

