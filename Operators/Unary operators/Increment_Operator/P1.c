/** Increment operator (Post and Pre) **/

#include<stdio.h>
void main()
{

    /**
    int a = 10;
    a++;
    printf("a = %d\n",a); // 11
    printf("a = %d\n",++a); //
    printf("a = %d\n",a); **/

    int a = 10;
    int b = 12;
    //int c = a++ + b++ + ++b + ++a;
    int c = a++ - b++ + ++b - ++a - ++a - a + b - a++ + b++ + c;
    printf("A = %d, B = %d, C = %d\n",a,b,c);
}

