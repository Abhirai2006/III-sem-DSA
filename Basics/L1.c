#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    float data1;
    struct node *next;
};

int main()
{
    struct node *head = NULL;   // Start of the list
    struct node *temp = NULL;   // Temporary pointer for new node
    struct node *tail = NULL;   // To keep track of the last node

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        // Create a new node
        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d %f", &temp->data,&temp->data1);
        temp->next = NULL;

        if (head == NULL)
        {
            // First node
            head = temp;
            tail = temp;
        }
        else
        {
            // Attach to the end
            tail->next = temp;
            tail = temp;
        }
    }

    // Display the linked list
    printf("\nLinked list elements:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d  and %.2f-> ", temp->data,temp->data1);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free the linked list
    temp = head;
    while (temp != NULL)
    {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
