#include <stdio.h>

int fibonacci(int n) // n = 3
{
    if(n == 1)
        return 0;               // Base case
    else if(n == 2 || n == 3)
        return 1;               // Base case
    else
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive call
}

int main()
{
    int n, i;
    printf("Enter how many terms you want: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for(i = 1; i <= n; i++)
    {
        printf("\n%d. %d\n", i,fibonacci(i));
    }

    return 0;
}

