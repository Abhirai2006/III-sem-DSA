/** Creation of a Doubly Linked List **/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void display();

struct node *head = NULL;
struct node *new_node = NULL;
struct node *temp = NULL;

void main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter the data for the %d node: ",i+1);
        scanf("%d",&new_node->data);

        new_node->next = NULL;
        new_node->prev = NULL;

        if(head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            new_node->prev = temp;
            temp = new_node;
        }
    }
    display();
}

void display()
{
    if(head == NULL)
    {
        printf("NULL.\n");
        return;
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d <-> ",temp->data);
            temp = temp->next;
        }
        printf("NULL.\n");
    }
}
