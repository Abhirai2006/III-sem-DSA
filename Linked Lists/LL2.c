#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void main()
{
    struct node *new_node = NULL;
    struct node *temp = NULL;
    struct node *head = NULL;

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

        printf("Enter the data: ");
        scanf("%d",&new_node->data);
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

        printf("Enter the choice (1 to insert, 0 to exit): ");
        scanf("%d", &choice);
    }

    temp = head;
    while(temp!=NULL)
    {
        printf("|data = %d and address = %x| -> ",temp->data,temp->next);
        temp = temp->next;
    }
    printf("NULL\n");
}
