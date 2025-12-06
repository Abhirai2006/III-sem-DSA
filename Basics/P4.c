#include<stdio.h>
#include<stdlib.h>

struct college
{
    int est_year;
    char c_name[30];
};

void main()
{
    int n;
    printf("Enter the number of colleges:\n");
    scanf("%d",&n);
    struct college *ptr = (struct college*)malloc(n * sizeof(struct college));
    if(ptr == NULL)
        printf("Memory allocation failed.\n");
    else
        printf("Memory allocated successfully and the memory is %p.\n",(void*)ptr);

    for(int i=0; i<n; i++)
    {
        printf("Enter the name and established year of the %d college\n", i+1);
        scanf("%s %d", (ptr + i)->c_name, &(ptr + i)->est_year);
    }


    for(int i=0; i<n; i++)
    {
        printf("The name and established year of the %d college is...\n", i+1);
        printf("%s %d\n", (ptr + i)->c_name, (ptr + i)->est_year);
    }

    free(ptr);
}
