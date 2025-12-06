#include<stdio.h>
#include<stdlib.h>
#define N 100

struct movie
{
    char name[N];
    float budget;
    int r_year;
};

void main()
{
    int n;
    printf("Enter the number of movies:\n");
    scanf("%d",&n);
    struct movie mov[n];
    struct movie *ptr = mov;
    for(int i=0; i<n; i++)
    {
        printf("Enter the details of the %d movie:",i+1);
        scanf("%s %f %d",(ptr + i)->name,&(ptr + i)->budget, &(*(ptr + i)).r_year);
        printf("%x %x %x\n",*(ptr+i),(ptr+i),&(*(ptr + i)).r_year);
    }
    for(int i=0; i<n; i++)
    {
        printf("%s %f %d\n",(ptr + i)->name,(ptr + i)->budget, (*(ptr + i)).r_year);
    }
}
