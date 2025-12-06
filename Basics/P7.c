#include<stdio.h>
#include<stdlib.h>
#define N 100

struct college
{
    char *c_name;
    struct department *dep;
    int d_count;
};

struct department
{
    char *dep_name;
};

void main()
{
    int n;
    printf("Enter the number of colleges:\n");
    scanf("%d",&n);
    printf("n = %d\n",n);

    struct college *coll = (struct college*)malloc(n * sizeof(struct college));
    if(coll == NULL)
        printf("Memory allocation failed.\n");
    else
        printf("Memory allocated successfully and the address is %p.\n",(void*)coll);

    // Start allocating memory
    for(int i=0; i<n; i++)
    {
        (coll + i)->c_name = (char*)malloc(N * sizeof(char));
        if((coll + i)->c_name == NULL)
            printf("Memory allocation failed.\n");
        else
            printf("Memory allocated successfully and the address is %p.\n",(void*)(coll + i)->c_name);

        // Now input
        printf("Details of the %d college...\n",i+1);
        printf("Name of the %d college - ",i+1);
        scanf("%s",(coll + i)->c_name);

        // Input for departments
        printf("Enter the number of departments in %s college - ",(coll + i)->c_name);
        scanf("%d",&(coll + i)->d_count);

        (coll + i)->dep = malloc((coll + i)->d_count * sizeof(struct department));
        if((coll + i)->dep == NULL)
            printf("Memory allocation failed.\n");
        else
            printf("Memory allocated successfully and the address is %p.\n",(void*)(coll + i)->dep);

        // Allocation of memory for department name
        for(int j=0; j<(coll + i)->d_count; j++)
        {
            (coll + i)->dep[j].dep_name = (char*)malloc(N * sizeof(char));
            printf("Enter the name of the %d department in %s - \n",j+1,(coll + i)->c_name);
            scanf("%s",(coll + i)->dep[j].dep_name);
        }

        // Now output
        printf("The details of the %d college are as follows...\n",i+1);
        printf("Name = %s\n",(coll + i)->c_name);
        printf("The Number of departments in %s college are %d\n",(coll + i)->c_name,(coll + i)->d_count);
        printf("The departments in %s are...\n",(coll + i)->c_name);
        for(int j=0; j<(coll + i)->d_count; j++)
        {
            printf(" %s\n", (coll + i)->dep[j].dep_name);
        }
    }
}
