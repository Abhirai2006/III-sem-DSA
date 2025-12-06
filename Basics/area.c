#include<stdio.h>
#define PI 3.14

void main()
{
    float radius,base,height,length,breadth,area1,area2,area3,area4;
    printf("Enter the values: ");
    //scanf("%f %f %f %f %f",&radius,&base,&height,&length,&breadth);
    area1 = PI * radius * radius;
    area2 = 0.5 * base * height;
    area3 = length * breadth;
    printf("area1 = %.2f, area2 = %.2f, area3 = %.2f",area1,area2,area3);
    printf("\n%d",sizeof(short));
}
