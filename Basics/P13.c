#include<stdio.h>
void main()
{
    int rows,cols;
    printf("Enter the number of rows and columns:\n");
    scanf("%d %d",&rows,&cols);
    int arr[rows][cols]; // data-type array-name [No of rows][No of cols]
    printf("Enter the elements of the array...\n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("Enter the element at [%d][%d] position:",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}
