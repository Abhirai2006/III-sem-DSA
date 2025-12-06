#include<stdio.h>
#include<stdlib.h>
void main()
{
    int rows,cols;
    printf("Enter the number of rows and columns:\n");
    scanf("%d %d",&rows,&cols);
    int **matrix = (int**)malloc(rows * sizeof(int*));
    if(matrix == NULL)
        printf("Memory allocation failed.\n");
    else
        printf("Memory allocated successfully and the address is %p\n",(void*)matrix);

    for(int i=0; i<rows; i++)
    {
        *(matrix + i) = (int*)malloc(cols * sizeof(int));
        if(*(matrix + i) == NULL)
            printf("Memory allocation failed.\n");
        else
            printf("Memory allocated successfully and the address is %p\n",(void*)*(matrix + i));
    }

    // Input
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("Enter the element at [%d][%d] location ",i,j);
            scanf("%d", *(matrix + i) + j);
        }
    }

    // Output
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("The element at [%d][%d] location is %d\n",i,j, *(*(matrix + i)+ j));
        }
    }

    // Free the memory
    for(int i=0; i<rows; i++)
    {
        free(*(matrix + i));
    }
    free(matrix);
}
