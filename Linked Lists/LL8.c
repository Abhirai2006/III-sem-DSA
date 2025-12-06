#include<stdio.h>
#include<stdlib.h>
#define N 100

struct node
{
    char *USN;
    char *Name;
    char *Branch;
    int sem;
    int age;
    char *phno;
    struct node *next;
};

struct node *new_node = NULL;
struct node *temp = NULL;
struct node *head = NULL;

int count = 0;

void insertbegin();
void insertposition();
void insertend();

void deletebegin();
void deleteposition();
void deleteend();

void display();
void length();

void main()
{
    int choice;
    printf("\nA MENU DRIVEN APPROACH FOR INSERTION AND DELETION OF STUDENT NODES.\n");
    while(1)
    {
        printf("\n================================================================\n");
        printf("1). Insert a student node at the beginning of the List.\n");
        printf("2). Insert a student node at a particular position in the List.\n");
        printf("3). Insert a student node at the end of the List.\n");
        printf("4). Delete a student node at the beginning of the List.\n");
        printf("5). Delete a student node at a particular position in the List.\n");
        printf("6). Delete a student node at the end of the List.\n");
        printf("7). Display the List.\n");
        printf("8). Length of the List.\n");
        printf("9). Exiting Program.\n");
        printf("================================================================\n");

        printf("Enter any one choice from the above: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insertbegin();
            break;

        case 2:
            insertposition();
            break;

        case 3:
            insertend();
            break;

        case 4:
            deletebegin();
            break;

        case 5:
            deleteposition();
            break;

        case 6:
            deleteend();
            break;

        case 7:
            display();
            break;

        case 8:
            length();
            break;

        case 9:
            printf("Exiting Program.\n");
            return;

        default:
            printf("Invalid choice.\n");
            return;
        }
    }
}

void insertbegin()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->USN = (char*)malloc(N * sizeof(char));
    new_node->Name = (char*)malloc(N * sizeof(char));
    new_node->Branch = (char*)malloc(N * sizeof(char));
    new_node->phno = (char*)malloc(N * sizeof(char));

    if(new_node->USN == NULL || new_node->Name == NULL || new_node->Branch == NULL || new_node->phno == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the USN of the student: ");
    scanf(" %[^\n]",new_node->USN);
    printf("Enter the name of the student: ");
    scanf(" %[^\n]",new_node->Name);
    printf("Enter the Branch of the student: ");
    scanf(" %[^\n]",new_node->Branch);
    printf("Enter the Ph.No of the student: ");
    scanf(" %[^\n]",new_node->phno);
    printf("Enter the sem of the student: ");
    scanf("%d",&new_node->sem);
    printf("Enter the age of the student: ");
    scanf("%d",&new_node->age);

    new_node->next = head;
    head = new_node;

    count++;

    printf("Node has been successfully inserted in the first position.\n");
}

void insertposition()
{
    int position;
    printf("Enter the position where you want to insert the node: ");
    scanf("%d",&position);

    if(position < 1 || position > count + 1)
    {
        printf("Invalid position.\n");
        return;
    }

    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->USN = (char*)malloc(N * sizeof(char));
    new_node->Name = (char*)malloc(N * sizeof(char));
    new_node->Branch = (char*)malloc(N * sizeof(char));
    new_node->phno = (char*)malloc(N * sizeof(char));

    if(new_node->USN == NULL || new_node->Name == NULL || new_node->Branch == NULL || new_node->phno == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the USN of the student: ");
    scanf(" %[^\n]",new_node->USN);
    printf("Enter the name of the student: ");
    scanf(" %[^\n]",new_node->Name);
    printf("Enter the Branch of the student: ");
    scanf(" %[^\n]",new_node->Branch);
    printf("Enter the Ph.No of the student: ");
    scanf(" %[^\n]",new_node->phno);
    printf("Enter the sem of the student: ");
    scanf("%d",&new_node->sem);
    printf("Enter the age of the student: ");
    scanf("%d",&new_node->age);


    if(position == 1 || head == NULL)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        temp = head;
        for(int i=1; i<position-1 ; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    count++;

    printf("The node has been successfully inserted in the %d position.\n",position);
}

void insertend()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->USN = (char*)malloc(N * sizeof(char));
    new_node->Name = (char*)malloc(N * sizeof(char));
    new_node->Branch = (char*)malloc(N * sizeof(char));
    new_node->phno = (char*)malloc(N * sizeof(char));

    if(new_node->USN == NULL || new_node->Name == NULL || new_node->Branch == NULL || new_node->phno == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the USN of the student: ");
    scanf(" %[^\n]",new_node->USN);
    printf("Enter the name of the student: ");
    scanf(" %[^\n]",new_node->Name);
    printf("Enter the Branch of the student: ");
    scanf(" %[^\n]",new_node->Branch);
    printf("Enter the Ph.No of the student: ");
    scanf(" %[^\n]",new_node->phno);
    printf("Enter the sem of the student: ");
    scanf("%d",&new_node->sem);
    printf("Enter the age of the student: ");
    scanf("%d",&new_node->age);


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

    count ++;

    printf("Node has been successfully inserted in the last position.\n");
}

void deletebegin()
{
    if(head == NULL)
    {
        printf("No nodes to delete. List is empty.\n");
        return;
    }
    else
    {
        temp = head;
        head = temp->next;

        free(temp->USN);
        free(temp->Name);
        free(temp->Branch);
        free(temp->phno);
        free(temp);
    }

    count--;

    printf("The first node has been deleted successfully.\n");
}

void deleteposition()
{
    struct node *prev = NULL;

    int position;
    printf("Enter the position from where you want to delete the node from: ");
    scanf("%d",&position);

    if(position < 1 || position > count)
    {
        printf("Invalid position.\n");
        return;
    }

    if(position == 1)
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    else
    {
        temp = head;
        for(int i = 1; i < position;  i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;

        free(temp->USN);
        free(temp->Name);
        free(temp->Branch);
        free(temp->phno);
        free(temp);
    }
    count--;

    printf("The node has been deleted successfully from the %d position.\n",position);
}

void deleteend()
{
    struct node *prev = NULL;

    if(head == NULL)
    {
        printf("No nodes to delete, List is empty.\n");
        return;
    }

    if(head->next == NULL)
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;

        free(temp->USN);
        free(temp->Name);
        free(temp->Branch);
        free(temp->phno);
        free(temp);
    }

    count--;

    printf("The last node has been successfully deleted.\n");
}

void display()
{
    if (head == NULL)
    {
        printf("\nNo nodes in the list. The list is empty.\n");
        return;
    }

    else
    {
        temp = head;
        printf("\n================== STUDENT DETAILS ==================\n");
        int i = 1;

        while (temp != NULL)
        {
            printf("\nStudent %d Details:\n", i++);
            printf("Name   : %s\n", temp->Name);
            printf("USN    : %s\n", temp->USN);
            printf("Age    : %d\n", temp->age);
            printf("Branch : %s\n", temp->Branch);
            printf("Sem    : %d\n", temp->sem);
            printf("Ph.No  : %s\n", temp->phno);
            temp = temp->next;
        }
        printf("=====================================================\n");
    }
    printf("NULL.\n");
}

void length()
{
    if(count == 0)
        printf("The list has %d node.\n",count);
    else
        printf("The list has %d nodes.\n",count);
}
