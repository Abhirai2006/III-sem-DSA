#include<stdio.h>
void main()
{
    int a = 100;
    int *ptr = &a;
    int **ptr1 = &ptr;
    int ***ptr2 = &ptr1;
    printf("%d %d %d %d\n",a,*ptr,*(*ptr1),*(*(*ptr2)));
    ***ptr2 = 300;
    printf("%d %d %d %d\n",a,*ptr,*(*ptr1),*(*(*ptr2)));
    **ptr2 = 30;
    printf("%x %x",ptr2,&ptr1);

/**This changes the value of ptr itself (not a), and assigns it the value 30.
But ptr is of type int*, so assigning 30 (an integer) to it is actually assigning
an invalid memory address to the pointer.
This is not safe and can lead to undefined behavior **/

}
