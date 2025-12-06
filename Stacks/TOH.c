#include <stdio.h>

void towerOfHanoi(int n, char from, char aux, char to)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    towerOfHanoi(n - 1, from, to, aux);

    printf("Move disk %d from %c to %c\n", n, from, to);

    towerOfHanoi(n - 1, aux, from, to);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nSteps to solve Tower of Hanoi:\n");
    towerOfHanoi(n, 'A', 'B', 'C');  // A = source, B = auxiliary, C = destination

    return 0;
}

