#include<Stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display();

struct node *new_node = NULL;
struct node *head = NULL;
struct node *temp = NULL;
struct node *tail = NULL;

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

        printf("Enter the data for the %d node: ",i + 1);
        scanf("%d",&new_node ->data);

        new_node ->next = NULL;

        if(head == NULL)
        {
            head = tail = new_node;
            tail ->next = head;
        }

        else
        {
            tail ->next = new_node;
            tail = new_node;
            tail ->next = head;
            **

            /**
            tail->next = new_node;
            new_node->next = head;
            tail = new_node;
            **/
        }
    }

    display();
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    else
    {
        temp = head;
        while(temp ->next != head)
        {
            printf("%d",temp ->data);
            temp = temp ->next;
        }
        printf("%d",temp ->data);
    }
}
