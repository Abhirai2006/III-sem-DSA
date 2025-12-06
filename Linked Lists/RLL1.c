#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;
struct node *new_node = NULL;

void display();

void main()
{
    int choice;
    printf("Enter the choice (1 to continue inserting, 0 to stop): ");
    scanf("%d",&choice);

    while(choice)
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
            head = temp = new_node;
        }
        else
        {
            temp = head;
            temp->next = new_node;
            temp = temp->next;
        }

        printf("Enter the choice  again(1 to continue inserting, 0 to stop): ");
        scanf("%d",&choice);
    }

    display();
}

void display()
{
    if(head == NULL)
    {
        printf("No nodes in the list.\n");
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
