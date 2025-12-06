#include<stdio.h>
#define N 100

typedef struct employee
{
    int e_id;
    char e_name[N];
    float salary;
} employee;

void main()
{
    int n;
    printf("Enter the number of employees:");
    scanf("%d",&n);
    employee e[n];
    employee *emp = &e;
    for(int i=0; i<n; i++)
    {
        printf("Enter the ID, Name and salary of the %d employee:",i+1);
        scanf("%d %s %f",&(emp + i)->e_id, (emp + i)->e_name, &(*(emp + i)).salary);
    }
    for(int i=0; i<n; i++)
    {
        printf("The ID, Name and salary of the %d employee is...\n",i+1);
        printf("%d %s %.2f\n",(emp + i)->e_id, (emp + i)->e_name, (*(emp + i)).salary);
    }

}
