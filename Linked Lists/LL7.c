#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertatthebeginning();
void insertataposition();
void insertattheend();
void deleteatthebeginning();
void deleteataposition();
void deleteattheend();
void lengthofthelist();
void display();

struct node *head = NULL;
struct node *new_node = NULL;
struct node *temp = NULL;

int count = 0;

void main()
{
    int choice;
    while(1)
    {
        printf("\n==== SINGLY LINKED LIST MENU ====\n");
        printf("1) Insert a node at the beginning\n");
        printf("2) Insert a node at a particular position\n");
        printf("3) Insert a node at the end\n");
        printf("4) Delete a node at the beginning\n");
        printf("5) Delete a node at a particular position\n");
        printf("6) Delete a node at the end\n");
        printf("7) Display the list\n");
        printf("8) Length of the list\n");
        printf("9) Exit\n");
        printf("=================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

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
            lengthofthelist();
            break;

        case 9:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid option. Try again.\n");
        }
    }
}

void insertatthebeginning()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the data for the node: ");
    scanf("%d",&new_node->data);

    new_node->next = head;
    head = new_node;

    count ++;
    printf("Node has been successfully inserted in the 1st position.\n");
}

void insertataposition()
{
    int position;
    printf("Enter the position you want to insert at: ");
    scanf("%d",&position);

    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the data for the node: ");
    scanf("%d",&new_node->data);

    if(position < 1 || position > count + 1)
    {
        printf("Invalid position.\n");
        free(new_node);
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

void insertattheend()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the data for the node: ");
    scanf("%d",&new_node->data);
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    count++;
    printf("Node has been successfully inserted in the last position.\n");
}

void deleteatthebeginning()
{
    if(head == NULL)
    {
        printf("List is empty, Nothing to delete.\n");
        return;
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
        count--;
    }
    printf("The first has been successfully deleted from the list.\n");
}

void deleteataposition()
{
    int position;
    printf("Enter the position from where you want to delete the node from: ");
    scanf("%d",&position);

    if(position < 1 || position > count)
    {
        printf("Invalid position.\n");
        return;
    }

    if(head == NULL)
    {
        printf("List is empty, Nothing to delete.\n");
        return;
    }

    if(position == 1)
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    else
    {
        struct node *prev;
        temp = head;
        for(int i=1; i<position; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    count--;
    printf("The node in the %d position has been deleted.\n",position);
}

void deleteattheend()
{
    if(head == NULL)
    {
        printf("The list is empty, no nodes to delete.\n");
        return;
    }

    if(head->next == NULL)
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    else
    {
        struct node *prev = NULL;
        temp = head;
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    count--;
    printf("The last node in the list has been deleted successfully.\n");
}

void display()
{
    if(head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL.\n");
    }
}

void lengthofthelist()
{
    printf("The list has %d nodes.\n",count);
}





