#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Length = %d\n", (int)strlen(str));

    // Print ASCII codes of all characters read
    for (int i = 0; i < strlen(str) + 1; i++) {
        printf("Index %d: char='%c' ASCII=%d\n", i, str[i], str[i]);
    }

    return 0;
}

