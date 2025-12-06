#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *new_node = NULL;
struct node *temp = NULL;

void main()
{
    int choice;
    printf("Enter the choice (1 to insert, 0 to stop): ");
    scanf("%d",&choice);

    while(choice)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            printf("Memory allocation failed.\n");
            return 0;
        }

        int data;
        printf("Enter the data: ");
        scanf("%d",&data);

        new_node->data = data;
        new_node->next = NULL;

        if(head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }

        printf("Enter the choice (1 to insert, 0 to stop): ");
        scanf("%d",&choice);

    }

    temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
