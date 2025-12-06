#include<stdio.h>
#include<stdlib.h>

struct employee
{
    int age;
    char name[50];
    float salary;
};

void main()
{
    // printf("%d\n",sizeof(struct employee));

    struct employee *ptr = (struct employee*)malloc(3 * sizeof(struct employee));
    if(ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    for(int i=0; i<3; i++)
    {
        printf("Enter the details of the %d student.\n",i+1);
        printf("Enter the name of the employee: ");
        scanf("%s",(ptr+i)->name);

        printf("Enter the age of the employee: ");
        scanf("%d",&(ptr+i)->age);

        printf("Enter the salary of the employee: ");
        scanf("%f",&(ptr+i)->salary);
    }

    for(int i=0; i<3; i++)
    {
        printf("Student %d details...\n",i+1);
        printf("Name = %s\n",(ptr+i)->name);
        printf("Age = %d\n",(ptr+i)->age);
        printf("Salary = %.2f\n",(ptr+i)->salary);
    }

}
