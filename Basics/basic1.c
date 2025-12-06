#include<stdio.h>
void main()
{
    char name[50];
    int age;
    char college_name[50];

    printf("Enter the name, age and college name: ");
    scanf("%s %d %s",name,&age,college_name);

    printf("Name = %s, Age = %d and college name = %s",name,age,college_name);


}
