#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Function to create a node in the beginning of the List.
void beginlist();

void main()
{
    struct node *head = NULL;
    struct node *new_node = NULL;
    struct node *temp = NULL;

    int choice;
    printf("Enter the choice(1 to insert 0 to exit): ");
    scanf("%d",&choice);

    while(choice)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
            printf("Memory allocation failed.\n");
        else
            printf("Memory allocated successfully.\n");

        printf("Enter the DATA for the node: ");
        scanf("%d",&new_node->data);
        new_node->next=NULL;

        if(head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }

        printf("Enter the choice (1 to insert, 0 to exit): ");
        scanf("%d", &choice);
    }

    temp = head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
