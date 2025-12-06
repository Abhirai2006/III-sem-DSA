#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;
struct node *new_node = NULL;

void insertatbeginning();
void insertatend();
void insertatposition();
void display();

int count = 0;
int position;

void main()
{
    int choice;

    while (1)
    {
        printf("1. Create (insert at end)");
        printf("\n2. Insert at beginning");
        printf("\n3. Insert at a particular position");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertatend();
            break;

        case 2:
            insertatbeginning();
            break;

        case 3:
            insertatposition();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}

void insertatbeginning()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    else
        printf("Memory allocated successfully.\n");

    printf("Enter the data for the node: ");
    scanf("%d", &new_node->data);

    new_node->next = head;
    head = new_node;
    count++;
}

void insertatend()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
    }
    printf("Memory allocated successfully.\n");

    printf("Enter the data for the node: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL)
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
        temp->next=new_node;
    }
    count++;
}

void insertatposition()
{
    int i;
    new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the position where you want to insert the node: ");
    scanf("%d", &position);

    if (position < 1 || position > count + 1)
    {
        printf("Invalid position.\n");
        free(new_node);
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &new_node->data);

    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        temp = head;
        for (i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    count++;
}

void display()
{
    temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
