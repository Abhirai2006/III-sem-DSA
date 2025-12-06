#include<stdio.h>
#include<stdlib.h>
#define N 100

struct employee
{
    char *name;
    char *department;
    char *designation;
    int emp_id;
    float salary;
};

struct company
{
    char *name;
    char *location;
    char *industry_type;
    int established_year;
    int num_employees;
    struct employee *emp;
};

void main()
{
    int n;
    printf("Enter the number of companies:");
    scanf("%d",&n);

    struct company *ptr = (struct company*)malloc(n * sizeof(struct company));
    if(ptr == NULL)
        printf("Memory allocation failed.\n");
   // else
     //   printf("Memory allocated successfully and the address is %p.\n",(void*)ptr);

    for(int i=0; i<n; i++)
    {
        (ptr+i)->name = (char*)malloc(N * sizeof(char));
        (ptr+i)->location = (char*)malloc(N * sizeof(char));
        (ptr+i)->industry_type = (char*)malloc(N * sizeof(char));

        if((ptr+i)->name == NULL || (ptr+i)->location == NULL || (ptr+i)->industry_type == NULL)
            printf("Memory allocation failed.\n");
       // else
         //   printf("Memory allocated successfully.The addresses are name = %p,location = %p and industry type = %p\n",(ptr+i)->name,(ptr+i)->location,(ptr+i)->industry_type);
    }

    for(int i=0; i<n; i++)
    {
        printf("----Enter the details of the %d company----\n",i+1);
        printf("Enter the name of the %d company:",i+1);
        scanf(" %[^\n]",(ptr+i)->name);
        printf("Enter the location of the %s:",(ptr+i)->name);
        scanf(" %[^\n]",(ptr+i)->location);
        printf("What type of industry is %s ?:",(ptr+i)->name);
        scanf(" %[^\n]",(ptr+i)->industry_type);
        printf("When was %s established:",(ptr+i)->name);
        scanf("%d",&(ptr+i)->established_year);
        printf("Enter the number of employees in %s:",(ptr+i)->name);
        scanf("%d",&(ptr+i)->num_employees);

        (ptr+i)->emp = (struct employee*)malloc((ptr+i)->num_employees * sizeof(struct employee));
        if((ptr+i)->emp == NULL)
            printf("Memory allocation failed.\n");
       /** else
            printf("Memory allocated successfully.\n"); **/

        for(int j=0; j<(ptr+i)->num_employees; j++)
        {
            ((ptr+i)->emp+j)->name = (char*)malloc(N * sizeof(char));
            ((ptr+i)->emp+j)->department = (char*)malloc(N * sizeof(char));
            ((ptr+i)->emp+j)->designation = (char*)malloc(N * sizeof(char));

            if(((ptr+i)->emp+j)->name == NULL || ((ptr+i)->emp+j)->department == NULL || ((ptr+i)->emp+j)->designation == NULL)
                printf("Memory allocation failed.\n");
          //  else
               // printf("Memory allocated successfully.\n");

            printf("\n---- Enter details of Employee %d in %s ----\n", j + 1, (ptr + i)->name);

            printf("Name: ");
            scanf(" %[^\n]", ((ptr + i)->emp + j)->name);

            printf("Department: ");
            scanf(" %[^\n]", ((ptr + i)->emp + j)->department);

            printf("Designation: ");
            scanf(" %[^\n]", ((ptr + i)->emp + j)->designation);

            printf("Employee ID: ");
            scanf("%d", &((ptr + i)->emp + j)->emp_id);

            printf("Salary: ");
            scanf("%f", &((ptr + i)->emp + j)->salary);
        }
    }


    printf("\n\n---- COMPANY AND EMPLOYEE DETAILS ----\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nCompany %d:\n", i + 1);
        printf("Name: %s\n", (ptr + i)->name);
        printf("Location: %s\n", (ptr + i)->location);
        printf("Industry: %s\n", (ptr + i)->industry_type);
        printf("Established: %d\n", (ptr + i)->established_year);
        printf("Number of employees: %d\n", (ptr + i)->num_employees);

        for (int j = 0; j < (ptr + i)->num_employees; j++)
        {
            printf("\n  Employee %d:\n", j + 1);
            printf("  Name: %s\n", ((ptr + i)->emp + j)->name);
            printf("  Department: %s\n", ((ptr + i)->emp + j)->department);
            printf("  Designation: %s\n", ((ptr + i)->emp + j)->designation);
            printf("  ID: %d\n", ((ptr + i)->emp + j)->emp_id);
            printf("  Salary: %.2f\n", ((ptr + i)->emp + j)->salary);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (ptr + i)->num_employees; j++)
        {
            free(((ptr + i)->emp + j)->name);
            free(((ptr + i)->emp + j)->department);
            free(((ptr + i)->emp + j)->designation);
        }
        free((ptr + i)->emp);
        free((ptr + i)->name);
        free((ptr + i)->location);
        free((ptr + i)->industry_type);
    }
    free(ptr);
}

