#include<stdio.h>
#define N 1009
const int a = 100;
void main()
{
    printf("Constant variable a = %d\n",a);
    int a = 30;
    printf("Local variable a = %d\n",a);
    printf("Defined variable N = %d\n",N);
    a = 40;
    printf("Local variable a = %d\n",a);
}
