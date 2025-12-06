#include<stdio.h>

union student
{
    int age;
    char name[20];
};

void main()
{
    union student stud;
    printf("Enter the age and name of the student: ");
    scanf("%d %s",&stud.age,stud.name);
    printf("The name of the student is %s and age of the student is %d",stud.name,stud.age);
}
