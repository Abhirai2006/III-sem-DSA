#include<stdio.h>
void main()
{
    int a = 5, b = 10;

    printf("Bitwise AND(&) = %d\n",a & b); // 0
    printf("Bitwise OR(|) = %d\n",a | b); // 15
    printf("Bitwise XOR(^) = %d\n",a ^ b); // 15
    printf("%d\n",a | b && b + 1 || 0 || b++); //
    printf("%d\n",b);
    int c = a << 2;
    // printf("%d\n",a);
    printf("C = %d and A = %d\n",c,a);
    c = a >> 2;
    printf("%d\n",c);
}
