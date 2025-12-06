/** Program to find area of a circle **/ // Documentation section

#include <stdio.h> // Link section
#define PI 3.14 // Definition section
#define PI 3.14

float area; // Global declaration section
void calculate_area(float radius);

int main() // Main section
{
    float radius; // Declaration part
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    calculate_area(radius);
    printf("The area of the circle is %.2f\n", area); // area is a global variable.
    printf("%.2f",PI);
    return 0;
}

void calculate_area(float radius) // Sub program section
{
    area = PI * radius * radius;
    printf("%.2f\n",area);
}
