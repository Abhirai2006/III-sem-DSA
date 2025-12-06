#include<stdio.h>
#include<stdlib.h>
#define N 100
struct student
{
    int age;
    char name[N];
};
void main()
{
    int n;
    struct student *stud;
    printf("Enter the number of students:");
    scanf("%d",&n);
    stud = (struct student*)calloc(n, sizeof(struct student));
    for(int i=0; i<n; i++)
        scanf("%d %s",&(stud+i)->age,(*(stud+i)).name);
    for(int i=0; i<n; i++)
        printf("%d %s",(stud+i)->age,(*(stud+i)).name);

}
