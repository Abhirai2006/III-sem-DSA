#include<stdio.h>
void main()
{
    float area,length,breadth,perimeter;
    printf("ENTER THE VALUES: ");
    scanf("%f %f",&length,&breadth);
    area = length *  breadth;
    perimeter = (2 * (length + breadth));

    printf("Area = %.2f and perimeter = %.2f",area,perimeter);
}
