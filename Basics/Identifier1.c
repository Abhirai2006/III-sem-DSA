#include <stdio.h>

// 'greet' is an identifier (function name)
void greet() {
    printf("Hello World\n");
}

int main() {   // 'main' is an identifier (function name)
    int age = 20;   // 'age' is an identifier (variable)

    printf("Age = %d\n", age); // using variable
    greet();                   // using function identifier

    return 0;
}

