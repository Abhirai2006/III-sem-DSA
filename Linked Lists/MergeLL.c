#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display1();
void display2();
void merge();

struct node *new_node = NULL;
struct node *temp = NULL;
struct node *head = NULL;

struct node *new_node1 = NULL;
struct node *temp1 = NULL;
struct node *head1 = NULL;


void main()
{
    int size1,size2;
    printf("Enter the size of the two linked lists: ");
    scanf("%d %d",&size1,&size2);

    // First Linked List Creation

    printf("Data for the first Linked List.\n");

    for(int i=0; i<size1; i++)
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
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }

    // Display the first List

    display1();

    // Second Linked List Creation

    printf("\nData for the second Linked List.\n");

    for(int i=0; i<size2; i++)
    {
        new_node1 = (struct node*)malloc(sizeof(struct node));
        if(new_node1 == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter the data for the %d node: ",i+1);
        scanf("%d",&new_node1->data);

        new_node1->next = NULL;

        if(head1 == NULL)
        {
            head1 = temp1 = new_node1;
        }
        else
        {
            temp1->next = new_node1;
            temp1 = new_node1;
        }
    }

    // Display the second List

    display2();

    merge();

    display2();
}

void display1()
{
    printf("Details of the first List.\n");

    if(head == NULL)
    {
        printf("List is empty, No nodes.\n");
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

void display2()
{
    printf("Details of the second List.\n");

    if(head1 == NULL)
    {
        printf("List is empty, No nodes.\n");
        return;
    }
    else
    {
        temp1 = head1;
        while(temp1 != NULL)
        {
            printf("%d -> ",temp1->data);
            temp1 = temp1->next;
        }
        printf("NULL.\n");
    }
}

void merge()
{
    temp1 = head1;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = head;
}
