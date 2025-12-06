#include<stdio.h>
void main()
{
    short a = -32768; // short int and short are same.
    printf("%d %d",sizeof(short int),sizeof(short));
    printf("\n%hu",a);
    printf("\n%hd",a);
    short b = 32770;   // 32780
    printf("\n%hd %hu",b,b);
    short c = -10;
    printf("\n%hd %hu",c,c);
    short d = -32772; // -32770
    printf("\n%hd %hu",d,d);
}
