#include <stdio.h>
void main
{
    char ch;
    int a, b, result;
    float div_result;

    printf("Enter any operator (+, -, *, /, %%):\n");
    scanf(" %c", &ch);

    switch (ch)
    {
    case '+':
        printf("Enter any two numbers:\n");
        scanf("%d %d", &a, &b);
        printf("Result = %d\n", result = a + b);
        break;

    case '-':
        printf("Enter any two numbers:\n");
        scanf("%d %d", &a, &b);
        printf("Result = %d\n", result = a - b);
        break;

    case '*':
        printf("Enter any two numbers:\n");
        scanf("%d %d", &a, &b);
        printf("Result = %d\n", result = a * b);
        break;

    case '/':
        printf("Enter any two numbers:\n");
        scanf("%d %d", &a, &b);
        if (b != 0)
        {
            div_result = (float)a / b;   // cast for float division
            printf("Result = %.2f\n", div_result);
        }
        else
        {
            printf("Error: Division by zero!\n");
        }
        break;

    case '%':
        printf("Enter any two numbers:\n");
        scanf("%d %d", &a, &b);
        if (b != 0)
        {
            printf("Result = %d\n", result = a % b);
        }
        else
        {
            printf("Error: Modulus by zero!\n");
        }
        break;

    default:
        printf("You have entered an invalid operator.\n");
        break;
    }

    return 0;
}
