/** Program to maintain tail**/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail = NULL;
struct node *temp = NULL;
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

        printf("Enter the data: ");
        scanf("%d",&new_node ->data);

        new_node ->next = NULL;

        if(tail == NULL)
        {
            tail = new_node;
            tail ->next = new_node;
        }

        else
        {
            new_node ->next = tail ->next;
            tail ->next = new_node;
            tail = new_node;
        }
    }

    temp = tail ->next;
    while(temp ->next != tail ->next)
    {
        printf("%d ",temp ->data);
        temp = temp ->next;
    }
    printf("%d ",temp ->data);
}
