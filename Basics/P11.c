//-- Documentation section tells us about the program. (Double Pointer) --//

#include<stdio.h>
void main()
{
    int n,*ptr,**ptr1,***ptr2;
    scanf("%d",&n);
    ptr = &n;
    ptr1 = &ptr;
    ptr2 = &ptr1;
    printf("n = %d  n = %d  n = %d  n = %d",n,*ptr,**ptr1,***ptr2);
}
