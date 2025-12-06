#include<stdio.h>
void main()
{
    printf("-----Options are as follows-----\n");
    printf("1)for-loop\n2)while loop\n3)do-while loop\n");
    int option;
    printf("Enter the option(1 or 2 or 3):");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        printf("YOU HAVE CHOSEN FOR LOOP\n");
        int a;
        printf("Enter the value of a:");
        scanf("%d",&a);
        for(int i=0; i<a; i++)
            printf("%d ",i+1);
        break;

    case 2:
        printf("YOU HAVE CHOSEN WHILE LOOP\n");
        int n,count = 0;
        printf("Enter the value of n:");
        scanf("%d",&n);
        int temp = n;
        while(n!=0)
        {
            n = n/10;
            count++;
        }
        printf("The number of digits in %d is %d.",temp,count);
        break;

    case 3:
    {
        printf("YOU HAVE CHOSEN DO-WHILE LOOP\n");
        int rows, cols;
        printf("Enter the number of rows and columns: ");
        scanf("%d %d", &rows, &cols);
        int i = 0;
        do
        {
            int j = 0;
            do
            {
                printf("* ");
                j++;
            }
            while (j < cols);
            printf("\n");
            i++;
        }
        while (i < rows);
        break;
    }

    default:
        printf("Invalid option.\n");
    }
}
