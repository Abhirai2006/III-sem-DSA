#include <stdio.h>
#include <stdlib.h>
#define N 5

int stack[N];
int top = -1;

void push();
void pop();
void peek();
void display();
void checkPalindrome();
void checkPalindromeDigits();
void checkOverflow();
void checkUnderflow();

int main()
{
    int choice;
    while(1)
    {
        printf("1). Push\n");
        printf("2). Pop\n");
        printf("3). Peek\n");
        printf("4). Display\n");
        printf("5). Palindrome\n");
        printf("6). Palindrome Digits\n");
        printf("7). Overflow\n");
        printf("8). Underflow\n");
        printf("9). Exit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            checkPalindrome();
            break;

        case 6:
            checkPalindromeDigits();
            break;

        case 7:
            checkOverflow();
            break;

        case 8:
           checkUnderflow();
            break;

        case 9:
            printf("Exiting Program.\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

void push()
{
    int x;
    printf("Enter the data you want to Push: ");
    scanf("%d", &x);

    if(top == N - 1)
    {
        printf("Overflow condition. Stack is full.\n");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("The element inserted to the top of the stack is %d.\n", x);
    }
}

void pop()
{
    int item;
    if(top == -1)
    {
        printf("Underflow condition. Stack is empty.\n");
    }
    else
    {
        item = stack[top];
        top--;
        printf("The popped element is %d.\n", item);
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Underflow condition. Stack is empty.\n");
    }
    else
    {
        printf("The element at the top is %d.\n", stack[top]);
    }
}

void display()
{
    if(top == -1)
    {
        printf("Underflow condition. Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for(int i = top; i >= 0; i--)
        {
            printf("Index %d -> %d\n", i, stack[i]);
        }
    }
}

void checkPalindrome()
{
    if (top == -1)
    {
        printf("Stack is empty, cannot check for palindrome.\n");
        return;
    }
    int flag = 1;
    for (int i = 0; i <= top / 2; i++)
    {
        if (stack[i] != stack[top - i])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("The stack is a palindrome.\n");
    }
    else
    {
        printf("The stack is not a palindrome.\n");
    }
}

void checkPalindromeDigits()
{
    if (top == -1)
    {
        printf("Stack is empty, cannot check for palindrome.\n");
        return;
    }

    char s[1024];
    s[0] = '\0';
    int pos = 0;

    for (int i = 0; i <= top; ++i) {

        pos += sprintf(s + pos, "%d", stack[i]);
    }

    int l = 0, r = pos - 1;
    int pal = 1;
    while (l < r) {
        if (s[l] != s[r]) { pal = 0; break; }
        l++; r--;
    }

    if (pal) printf("The stack is a palindrome (digit-wise: \"%s\").\n", s);
    else     printf("The stack is not a palindrome (digit-wise: \"%s\").\n", s);

}

void checkOverflow()
{
    if (top == N - 1)
    {
        printf("Stack is full! Overflow condition exists.\n");
    }
    else
    {
        printf("Stack is not full. No overflow.\n");
    }
}

void checkUnderflow()
{
    if (top == -1)
    {
        printf("Stack is empty! Underflow condition exists.\n");
    }
    else
    {
        printf("Stack is not empty. No underflow.\n");
    }
}

