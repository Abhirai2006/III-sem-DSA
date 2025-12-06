#include <stdio.h>

int main(void)
{
    printf("%d", sizeof(short));
    printf("\n%d", sizeof(short int));
    printf("\n%d", sizeof(long int));
    printf("\n%d", sizeof(int));
    printf("\n%d", sizeof(long));
    int a = 98;
    printf("\n%c", a);
    printf("\n%d", sizeof(char));
    printf("\n%d", sizeof(double));
    printf("\n%d", sizeof(long double));
    double b = 10.67;
    printf("\n%lf", b);
    return 0;
}
