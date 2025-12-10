/** Program to maintain head and tail pointer **/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *temp = NULL;
struct node *new_node = NULL;

void main()
{
    int n,count = 0;
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

        printf("Enter the data: ");
        scanf("%d",&new_node->data);

        new_node->next = NULL;
        new_node->prev = NULL;

        if(head == NULL)
        {
            head = tail = new_node;
            head->prev = head;
            head->next = head;
        }

        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            head->prev = new_node;
            new_node->next = head;
            tail = new_node;
        }

        count++;

        if(count == n)
        {
            temp = head;
            while(temp != tail)
            {
                printf("%d ",temp->data);
                temp = temp->next;
            }
            printf("%d",temp->data);
        }
    }
}
