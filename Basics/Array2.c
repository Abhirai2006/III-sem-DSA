#include<stdio.h>
void main()

struct student
{
    int age;
    char name[30];
};

{
    int arr[5] = {1,2};
    struct student stud[2] = {{10,"Thushar"},{20,"random"}};
    printf("%s\n",stud[1].name);


    // printf("%d\n",sizeof(arr)/sizeof(arr[0]));


    for(int i=0; i<5; i++)
    {
        printf("%d ",arr[i]);
    }
}
/** Operations on Arrays
1). Insertion (Beginning, any position and at the end)
2). Deletion  (Beginning, any position and at the end)
3). Display
4). Length
5). Reverse
6). Searching (Linear Search and Binary Search)
7). Traversal
8). Sorting **/
