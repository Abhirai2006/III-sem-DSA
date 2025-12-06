#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *new_node = NULL;
struct node *temp = NULL;
struct node *head = NULL;

void insertatbeginning();
void insertatposition();
void insertatend();

void deleteatbeginning();
void deleteatend();
void deleteatposition();

void getlength();
void display();

int count = 0;

void main()
{
    int choice;
    while(1)
    {
        printf("1).Insert at the beginning.\n");
        printf("2).Insert at a particular position.\n");
        printf("3).Insert at the end.\n");

        printf("4).Delete at the beginning.\n");
        printf("5).Delete at a particular position.\n");
        printf("6).Delete at the end.\n");

        printf("7).Length of the Linked List.\n");
        printf("8).Display the list.\n");
        printf("9).Exit.\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insertatbeginning();
            break;

        case 2:
            insertatposition();
            break;

        case 3:
            insertatend();
            break;

        case 4:
            deleteatbeginning();
            break;

        case 5:
            deleteatposition();
            break;

        case 6:
            deleteatend();
            break;

        case 7:
            getlength();
            break;

        case 8:
            display();
            break;

        case 9:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }

    }
}

// 1). Insert at the beginning of the list.
void insertatbeginning()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
        printf("Memory allocation failed.\n");
    else
        printf("Memory allocated successfully.\n");

    printf("Enter the data for the node: ");
    scanf("%d",&new_node->data);

    new_node->next = head;
    head = new_node;
    count++;
}

// 2). Insert at a particular position in the list.
void insertatposition()
{
    int position;
    printf("Enter the position of the node: ");
    scanf("%d",&position);

    new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    if(position < 1 || position > count + 1)
    {
        printf("Invalid position.\n");
        free(new_node);
        return;
    }

    printf("Enter the data: ");
    scanf("%d",&new_node->data);

    if(position == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        temp = head;
        for(int i = 1; i < position-1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    count++;
}


// 3). Insert at the end of the list.
void insertatend()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
        printf("Memory allocation failed.\n");
    else
        printf("Memory allocated successfully.\n");

    printf("Enter the data for the node: ");
    scanf("%d",&new_node->data);
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    count++;
}

// 4). Delete at the beginning of the list.
void deleteatbeginning()
{
    if(head == NULL)
    {
        printf("List is empty, Nothing to delete.\n");
        return;
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
        count--;
    }
}

// 5). Delete at a particular position in the list.
void deleteatposition()
{
    int position;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &position);

    if (head == NULL)
    {
        printf("List is empty, Nothing to delete.\n");
        return;
    }

    if(position < 1 || position > count)
    {
        printf("Invalid position.\n");
        return;
    }

    struct node *prev = NULL;
    temp = head;

    if(position == 1)
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        for(int i=1; i<position; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        free(temp);
    }

    count--;
}

// 6). Delete at the end of the list.
void deleteatend()
{
    if(head == NULL)
    {
        printf("List is empty, Nothing to delete.\n");
        return;
    }

    if(head->next == NULL)
    {
        temp = head;
        free(temp);
        head = NULL;
    }
    else
    {
        struct node *prev = NULL;
        temp = head;

        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    count--;
}

// 7). Length of the list.
void getlength()
{
    int length = 0;
    temp = head;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    printf("Length of the linked list is %d\n", length);
}


// 8). Display the list.
void display()
{
    temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL.\n");
    }
}
