#include <stdio.h>
#include <stdlib.h>
#define N 100

struct faculty
{
    char *faculty_name;
    int age;
    double salary;
};

struct student
{
    char *student_name;
    int age;
    double fees;
};

struct department
{
    char *department_name;
    int faculty_count;
};

struct college
{
    int est_year;
    char *c_name;
    float campus_dimension;

    struct faculty *faculties;
    int f_count;

    struct student *students;
    int student_count;

    struct department *departments;
    int department_count;
};

int main()
{
    int n;
    printf("Enter the number of colleges:\n");
    scanf("%d", &n);

    struct college *colleges = (struct college*)malloc(n * sizeof(struct college));
    if (colleges == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input details
    for (int i = 0; i < n; i++)
    {
        printf("\n--- Enter details of college %d ---\n", i + 1);

        (colleges + i)->c_name = (char*)malloc(N * sizeof(char));
        printf("College name: ");
        scanf(" %[^\n]", (colleges + i)->c_name);

        printf("Established year: ");
        scanf("%d", &(colleges + i)->est_year);

        printf("Campus dimension (acres): ");
        scanf("%f", &(colleges + i)->campus_dimension);

        // Faculties
        printf("Enter number of faculties: ");
        scanf("%d", &(colleges + i)->f_count);
        (colleges + i)->faculties = (struct faculty*)malloc((colleges + i)->f_count * sizeof(struct faculty));

        for (int j = 0; j < (colleges + i)->f_count; j++)
        {
            (colleges + i)->faculties[j].faculty_name = (char*)malloc(N * sizeof(char));
            printf(" Faculty %d name: ", j + 1);
            scanf(" %[^\n]", (colleges + i)->faculties[j].faculty_name);
            printf(" Age: ");
            scanf("%d", &((colleges + i)->faculties[j].age));
            printf(" Salary: ");
            scanf("%lf", &((colleges + i)->faculties[j].salary));
        }

        // Students
        printf("Enter number of students: ");
        scanf("%d", &(colleges + i)->student_count);
        (colleges + i)->students = (struct student*)malloc((colleges + i)->student_count * sizeof(struct student));

        for (int j = 0; j < (colleges + i)->student_count; j++)
        {
            (colleges + i)->students[j].student_name = (char*)malloc(N * sizeof(char));
            printf(" Student %d name: ", j + 1);
            scanf(" %[^\n]", (colleges + i)->students[j].student_name);
            printf(" Age: ");
            scanf("%d", &((colleges + i)->students[j].age));
            printf(" Fees: ");
            scanf("%lf", &((colleges + i)->students[j].fees));
        }

        // Departments
        printf("Enter number of departments: ");
        scanf("%d", &(colleges + i)->department_count);
        (colleges + i)->departments = (struct department*)malloc((colleges + i)->department_count * sizeof(struct department));

        for (int j = 0; j < (colleges + i)->department_count; j++)
        {
            (colleges + i)->departments[j].department_name = (char*)malloc(N * sizeof(char));
            printf(" Department %d name: ", j + 1);
            scanf(" %[^\n]", (colleges + i)->departments[j].department_name);
            printf(" Faculty count in %s: ", (colleges + i)->departments[j].department_name);
            scanf("%d", &((colleges + i)->departments[j].faculty_count));
        }
    }

    // Output details
    printf("\n========== COLLEGE DATABASE ==========\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nCollege %d:\n", i + 1);
        printf("Name: %s\n", (colleges + i)->c_name);
        printf("Established: %d\n", (colleges + i)->est_year);
        printf("Campus size: %.2f acres\n", (colleges + i)->campus_dimension);

        printf("Faculties:\n");
        for (int j = 0; j < (colleges + i)->f_count; j++)
        {
            printf(" %s | Age: %d | Salary: %.2lf\n",
                   (colleges + i)->faculties[j].faculty_name,
                   (colleges + i)->faculties[j].age,
                   (colleges + i)->faculties[j].salary);
        }

        printf("Students:\n");
        for (int j = 0; j < (colleges + i)->student_count; j++)
        {
            printf(" %s | Age: %d | Fees: %.2lf\n",
                   (colleges + i)->students[j].student_name,
                   (colleges + i)->students[j].age,
                   (colleges + i)->students[j].fees);
        }

        printf("Departments:\n");
        for (int j = 0; j < (colleges + i)->department_count; j++)
        {
            printf(" %s | Faculty count: %d\n",
                   (colleges + i)->departments[j].department_name,
                   (colleges + i)->departments[j].faculty_count);
        }
    }

    // Free memory
    for (int i = 0; i < n; i++)
    {
        free((colleges + i)->c_name);

        for (int j = 0; j < (colleges + i)->f_count; j++)
            free((colleges + i)->faculties[j].faculty_name);
        free((colleges + i)->faculties);

        for (int j = 0; j < (colleges + i)->student_count; j++)
            free((colleges + i)->students[j].student_name);
        free((colleges + i)->students);

        for (int j = 0; j < (colleges + i)->department_count; j++)
            free((colleges + i)->departments[j].department_name);
        free((colleges + i)->departments);
    }
    free(colleges);

    return 0;
}
