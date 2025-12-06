#include <stdio.h>
#include <stdlib.h>

void main()
{
    int size;
    printf("Enter the maximum size of the infix expression: ");
    scanf("%d", &size);

    char infix[size];

    printf("Enter the infix expression: ");
    fgets(infix, size, stdin);    // reads until newline or size-1 chars

    printf("You entered: %s", infix);
}
