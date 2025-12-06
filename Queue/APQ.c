#include <stdio.h>
#define N 20

int pqueue[N];
int front = -1, rear = -1;

void enqueue(int item)
{
    int i, j, temp;

    if (rear == N - 1) {
        printf("Queue Overflow\n");
        return;
    }

    // First insertion
    if (front == -1 && rear == -1) {
        front = rear = 0;
        pqueue[rear] = item;
    }
    else {
        rear++;
        pqueue[rear] = item;

        // Sort from front to rear (ascending)
        for (i = front; i < rear; i++) {
            for (j = i + 1; j <= rear; j++) {
                if (pqueue[i] > pqueue[j]) {
                    temp = pqueue[i];
                    pqueue[i] = pqueue[j];
                    pqueue[j] = temp;
                }
            }
        }
    }
}

void display()
{
    if (front == -1)
        printf("Queue empty\n");
    else {
        printf("Priority Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", pqueue[i]);
        printf("\n");
    }
}

int main()
{
    enqueue(10);
    display();

    enqueue(3);
    display();

    enqueue(7);
    display();

    enqueue(5);
    display();

    return 0;
}

