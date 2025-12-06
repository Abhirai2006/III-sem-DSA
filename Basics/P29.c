#include<stdio.h>
#include<stdlib.h>
struct demo
{
    int a;
    float b;
    char c;
};
void main()
{
    struct demo *ptr = (struct demo*)malloc(sizeof(struct demo));
    if(ptr == NULL)
        printf("Memory allocation failed.\n");
    else
        printf("Memory allocated successfully.\n");

    printf("%x",&(ptr->a));
    scanf("%d",&(ptr->a));
    scanf("%f",&(ptr->b));
    scanf(" %c",&(ptr->c));

    printf("a = %d, b = %.2f, c = %c",(ptr->a),(ptr->b),(ptr->c));

    free(ptr);
}

