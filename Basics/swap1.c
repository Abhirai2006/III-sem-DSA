#include<stdio.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void main()
{
    int a,b;
    printf("Enter the values for a and b: ");
    scanf("%d %d",&a,&b);

    printf("The values before swapping are a = %d and b = %d\n",a,b);

   /** int temp = a;
    a = b;
    b = temp; **/

    swap(a,b);

    printf("The values before swapping are a = %d and b = %d\n",a,b);
}
