#include<stdio.h>
void main()
{
    int n,count = 0;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int temp = n;
    while(n != 0)
    {
        n = n/10;
        count++;
    }
    printf("The number of digits in %d are %d\n",temp,count);
}
