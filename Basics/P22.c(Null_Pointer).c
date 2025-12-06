#include <stdio.h>
void main()
{
    int *ptr = NULL;
    if (ptr == NULL)
    {
        printf("The pointer is NULL. It doesn't point to any valid memory.\n");
    }
    int x = 100;
    ptr = &x;
    printf("After assigning, pointer points to x = %d\n", *ptr);
}

