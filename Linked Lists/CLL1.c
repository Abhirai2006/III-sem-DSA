#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
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

        if(head == NULL)
        {
            head = temp = new_node;
            temp->next = head;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
            temp->next = head;
        }
    }

    display();
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty, No nodes in the List.\n");
        return;
    }

    struct node *ptr = head;

    printf("\nCircular Linked List elements are:\n");

    while(ptr->next != head)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d -> (back to head)\n", ptr->data);
}
