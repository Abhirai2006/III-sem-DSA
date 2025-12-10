#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void display();

struct node *temp = NULL;
struct node *head = NULL;
struct node *new_node = NULL;

void main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter the data of the node: ");
        scanf("%d",&new_node->data);

        new_node->next = NULL;
        new_node->prev = NULL;

        if(head == NULL)
        {
            temp = head = new_node;
        }
        else
        {
            new_node->prev = temp;
            temp->next = new_node; // order of these two can be anything.
            temp = new_node; // temp = temp->next;
        }
    }

    display();
}

void display()
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL.\n");
}
