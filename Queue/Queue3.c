/**  Deque implementation using circular arrays **/

#include <stdio.h>
#define N 5

int deque[N];
int f = -1;
int r = -1;

void enqueuefront();
void enqueuerear();
void display();
void getfront();
void getrear();
void dequeuefront();
void dequeuerear();

void main()
{
    int choice;

    while (1)
    {
        printf("\n1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: enqueuefront(); break;
            case 2: enqueuerear(); break;
            case 3: dequeuefront(); break;
            case 4: dequeuerear(); break;
            case 5: getfront(); break;
            case 6: getrear(); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void enqueuefront()
{
    int x;
    printf("Enter value: ");
    scanf("%d", &x);

    if ((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("Deque is full\n");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0)
    {
        f = N - 1;
        deque[f] = x;
    }
    else
    {
        f--;
        deque[f] = x;
    }
}

void enqueuerear()
{
    int x;
    printf("Enter value: ");
    scanf("%d", &x);

    if ((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("Deque is full\n");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        deque[r] = x;
    }
    else if (r == N - 1)
    {
        r = 0;
        deque[r] = x;
    }
    else
    {
        r++;
        deque[r] = x;
    }
}

void display()
{
    if (f == -1 && r == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    int i = f;
    while (i != r)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", deque[r]);
}

void getfront()
{
    if (f == -1)
        printf("Deque empty\n");
    else
        printf("Front = %d\n", deque[f]);
}

void getrear()
{
    if (r == -1)
        printf("Deque empty\n");
    else
        printf("Rear = %d\n", deque[r]);
}

void dequeuefront()
{
    if (f == -1 && r == -1)
    {
        printf("Deque is empty\n");
    }
    else if (f == r)
    {
        printf("Deleted: %d\n", deque[f]);
        f = r = -1;
    }
    else if (f == N - 1)
    {
        printf("Deleted: %d\n", deque[f]);
        f = 0;
    }
    else
    {
        printf("Deleted: %d\n", deque[f]);
        f++;
    }
}

void dequeuerear()
{
    if (f == -1 && r == -1)
    {
        printf("Deque is empty\n");
    }
    else if (f == r)
    {
        printf("Deleted: %d\n", deque[r]);
        f = r = -1;
    }
    else if (r == 0)
    {
        printf("Deleted: %d\n", deque[r]);
        r = N - 1;
    }
    else
    {
        printf("Deleted: %d\n", deque[r]);
        r--;
    }
}
