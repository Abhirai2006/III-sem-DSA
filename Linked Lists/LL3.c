#include<stdio.h>
#include<stdlib.h>
#define N 100

struct node
{
    struct student
    {
        int age;
        char *s_name;
        float s_id;
    }*stud;

    struct node *next;
};

void main()
{
    struct node *new_node = NULL;
    struct node *temp = NULL;
    struct node *head = NULL;

    int choice;
    printf("Enter the choice(1 to insert 0 to exit): ");
    scanf("%d",&choice);

    int value = 1;

    while(choice)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
            printf("Memory allocation failed.\n");
        else
            printf("Memory allocated successfully.\n");

        new_node->stud = (struct student *)malloc(sizeof(struct student));
        if (new_node->stud == NULL)
        {
            printf("Memory allocation for student failed.\n");
            return 1;
        }

        new_node->stud->s_name = (char*)malloc(N * sizeof(char));
        if(new_node->stud->s_name == NULL)
            printf("Memory allocation failed.\n");
        else
            printf("Memory allocated successfully.\n");

        printf("Enter the details of the %d student\n",value);
        printf("Enter the age of the student: ");
        scanf("%d",&new_node->stud->age);

        printf("Enter the ID of the student: ");
        scanf("%f",&new_node->stud->s_id);

        printf("Enter the name of the student: ");
        scanf(" %[^\n]",new_node->stud->s_name);

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

        printf("Enter the choice (1 to insert, 0 to exit): ");
        scanf("%d", &choice);
        value++;
    }

    temp = head;
    while(temp!=NULL)
    {
        printf("Name = %s, Age = %d and ID = %.2f -> ",temp->stud->s_name,temp->stud->age,temp->stud->s_id);
        temp = temp->next;
    }
    printf("NULL\n");
}
