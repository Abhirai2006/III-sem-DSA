#include<stdio.h>

void main()
{
    int rows,cols;
    scanf("%d %d",&rows,&cols);

    int arr[rows][cols];

    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            scanf("%d",&arr[i][j]);

    printf("%d",arr[i]);
}
