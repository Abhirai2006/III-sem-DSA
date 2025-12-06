#include <stdio.h>

// 'calculate' is an identifier (function), not a variable
void calculate() {
    printf("This is a function.\n");
}

int main() {
    calculate();   // calling the function using its identifier
    return 0;
}

