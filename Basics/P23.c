#include<stdio.h>

typedef struct student
{
    int roll_no;
    char name[20];
    float marks;
} stud;

stud s3 = {3,"Lakshya",87.42};
stud s4;
void print();
void main()
{
    typedef struct student student;
    stud s1 = {1,"Thushar",98.56};
    student s2 = {2,"Apeksha",89.33};
    printf("%d %s %.2f\n",s1.roll_no,s1.name,s1.marks);
    printf("%d %s %.2f\n",s2.roll_no,s2.name,s2.marks);
    int n = 3;
    stud stu[n];
    printf("Enter the name, roll_no and marks:");
    scanf("%s %d %f",&s4.name,&s4.roll_no,&s4.marks);
    print();
    // The values of the objects can be assigned to each other object 1 = object 2.
}

void print()
{
    printf("%d %s %f\n",s3.roll_no,s3.name,s3.marks);
    printf("The name of my sister is %s\n",s3.name);
    printf("The name of my sister is %s\n",s4.name);
}

