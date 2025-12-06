#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *new_node, *temp;

void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition();
void displayForward();
void displayBackward();
void getLength();

int count = 0;

void main()
{
    int choice;
    while(1)
    {
        printf("\n========== DOUBLY LINKED LIST MENU ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Get Length\n");
        printf("10. Exit\n");
        printf("=============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtPosition();
            break;
        case 7:
            displayForward();
            break;
        case 8:
            displayBackward();
            break;
        case 9:
            getLength();
            break;
        case 10:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

// ================= INSERTION FUNCTIONS =================

// Insert at the beginning
void insertAtBeginning()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &new_node->data);

    new_node->prev = NULL;
    new_node->next = head;

    if(head != NULL)
        head->prev = new_node;
    else
        tail = new_node;

    head = new_node;
    count++;
}

// Insert at the end
void insertAtEnd()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if(head == NULL)
    {
        new_node->prev = NULL;
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    count++;
}

// Insert at a given position
void insertAtPosition()
{
    int pos;
    printf("Enter the position to insert (1 to %d): ", count + 1);
    scanf("%d", &pos);

    if(pos < 1 || pos > count + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1)
    {
        insertAtBeginning();
        return;
    }
    else if(pos == count + 1)
    {
        insertAtEnd();
        return;
    }

    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &new_node->data);

    temp = head;
    for(int i = 1; i < pos - 1; i++)
        temp = temp->next;

    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;

    count++;
}

// ================= DELETION FUNCTIONS =================

// Delete at beginning
void deleteAtBeginning()
{
    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    if(head->next == NULL)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
    count--;
}

// Delete at end
void deleteAtEnd()
{
    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = tail;
    if(tail->prev == NULL)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
    count--;
}

// Delete at a particular position
void deleteAtPosition()
{
    int pos;
    printf("Enter the position to delete (1 to %d): ", count);
    scanf("%d", &pos);

    if(pos < 1 || pos > count)
    {
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1)
    {
        deleteAtBeginning();
        return;
    }
    else if(pos == count)
    {
        deleteAtEnd();
        return;
    }

    temp = head;
    for(int i = 1; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    count--;
}

// ================= DISPLAY FUNCTIONS =================

// Display Forward
void displayForward()
{
    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("\nDoubly Linked List (Forward): ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display Backward
void displayBackward()
{
    if(tail == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("\nDoubly Linked List (Backward): ");
    temp = tail;
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Get Length of List
void getLength()
{
    printf("Length of the linked list: %d\n", count);
}

