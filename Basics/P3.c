#include<stdio.h>
#include<stdlib.h>

struct student
{
    int id;
    char name[50];
};

void main()
{
    int n;
    printf("Enter the number of students:\n");
    scanf("%d",&n);
    struct student s[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter the name and roll no of the %d student:\n",i + 1);
        scanf("%s %d",&s[i].name, &s[i].id);
    }

    for(int i=0; i<n; i++)
    {
        printf("The name and roll no of the %d student is %s and %d respectively.\n",i + 1, s[i].name, s[i].id);
    }
}
