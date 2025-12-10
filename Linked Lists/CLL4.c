/** A menu driven approach for a Circular Linked List **/

#include<stdio.h>
#include<stdlib.h>
#define N 100

struct node
{
    int data;
    char *name;
    struct node *next;
};
int count = 0;

struct node *new_node = NULL;
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

    new_node->next = NULL;

    if(tail == NULL)
    {
        tail = new_node;
        tail ->next = new_node;
    }
    else
    {
        new_node->next = tail ->next;
        tail ->next = new_node;
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

    new_node->next = NULL;

    if(tail == NULL)
    {
        tail = new_node;
        tail ->next = new_node;
    }
    else
    {
        new_node->next = tail ->next;
        tail ->next = new_node;
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

    new_node->next = NULL;


    temp = tail ->next;
    for(int i = 1; i < pos - 1; i++)
        temp = temp->next;

    new_node->next = temp->next;
    temp->next = new_node;

    printf("Node has been successfully inserted at %d position.\n",pos);
    count++;
}

void deletebegin()
{
    if(tail == NULL)
    {
        printf("The list is empty, it has no nodes to delete.\n");
        return;
    }

    temp = tail ->next;
    if(temp == tail)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
        tail ->next = temp ->next;
        free(temp);
    }
    count--;
    printf("A node has been successfully deleted from the front of the list.\n");
}

void deleteend()
{
    struct node *prev = NULL;

    if(tail == NULL)
    {
        printf("The list is empty, it has no nodes to delete.\n");
        return;
    }

    temp = tail->next;

    if(temp == tail)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
        while(temp ->next != tail ->next)
        {
            prev = temp;
            temp = temp->next;
        }

        prev ->next = temp ->next;
        free(temp);
        tail = prev;
    }
    count--;
    printf("A node has been successfully deleted from the end of the list.\n");
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
        deletebegin();
        return;
    }
    else if (pos == count)
    {
        deleteend();
        return;
    }
    else if(tail == NULL)
    {
        printf("The list is empty\n.");
        return;
    }
    else
    {
        temp = tail ->next;
        for (int i = 1; i < pos ; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev ->next = temp ->next;
        free(temp);
    }
    count--;
    printf("A node has been successfully deleted from %d position.\n",pos);

}

void display()
{
    if(tail == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    else
    {
        temp = tail ->next;
        while(temp ->next != tail ->next)
        {
            printf("%d %s->",temp ->data,temp->name);
            temp = temp ->next;
        }

        printf("%d %s->",temp ->data,temp ->name);
    }
}

void length()
{
    if(count == 0)
        printf("The list has no nodes so the length is %d\n",count);
    else
        printf("The number of nodes in the list are: %d\n",count);
}


