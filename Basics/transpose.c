/** In an array after transposing columns will become rows and the rows will become the columns. **/

#include<stdio.h>

void main()
{
    int rows,cols;
    printf("Enter the size of the matrix (rows*cols): ");
    scanf("%d %d",&rows,&cols);
    int arr[rows][cols];
    printf("Enter the elements of the matrix (%d * %d = %d): ",rows,cols,(rows*cols));
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("The elements of the matrix are as follows: \n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    printf("The array after transpose is: \n");
    for(int i=0; i<cols; i++)
    {
        for(int j=0; j<rows; j++)
        {
            printf("%d\t",arr[j][i]);
        }
        printf("\n");
    }
}
