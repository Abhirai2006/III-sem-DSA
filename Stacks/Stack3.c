#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// Simple stack for chars (operators and parentheses)
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX-1) stack[++top] = c;
}

char pop() {
    if (top >= 0) return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0) return stack[top];
    return '\0';
}

int isEmpty() {
    return top == -1;
}

// precedence: higher number => higher precedence
int precedence(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// returns 1 if op is right-associative
int isRightAssociative(char op) {
    if (op == '^') return 1;
    return 0;
}

// returns 1 if c is an operator
int isOperator(char c) {
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

int main() {
    char infix[MAX];
    char postfix[MAX*2]; // allow spaces between tokens
    int i = 0, k = 0;

    printf("Enter infix expression: ");
    if (!fgets(infix, sizeof(infix), stdin)) return 0;
    // remove trailing newline
    infix[strcspn(infix, "\n")] = '\0';

    int len = strlen(infix);

    while (i < len) {
        // skip spaces
        if (isspace((unsigned char)infix[i])) {
            i++;
            continue;
        }

        // If operand (letter/digit), copy the entire operand (supports multi-digit/identifiers)
        if (isalnum((unsigned char)infix[i])) {
            while (i < len && isalnum((unsigned char)infix[i])) {
                postfix[k++] = infix[i++];
            }
            // add a space to separate tokens in postfix output
            postfix[k++] = ' ';
        }
        // left parenthesis
        else if (infix[i] == '(') {
            push('(');
            i++;
        }
        // right parenthesis: pop until '('
        else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            if (!isEmpty() && peek() == '(') pop(); // remove '('
            else {
                // mismatched parentheses
                printf("Error: mismatched parentheses\n");
                return 1;
            }
            i++;
        }
        // operator
        else if (isOperator(infix[i])) {
            char op = infix[i];
            // Pop operators from stack to output while top has operator of higher precedence
            while (!isEmpty() && isOperator(peek())) {
                char topOp = peek();
                int pTop = precedence(topOp);
                int pOp  = precedence(op);

                if ((isRightAssociative(op) && pOp < pTop) || (!isRightAssociative(op) && pOp <= pTop)) {
                    postfix[k++] = pop();
                    postfix[k++] = ' ';
                } else break;
            }
            push(op);
            i++;
        }
        else {
            // unknown character
            printf("Error: unknown character '%c'\n", infix[i]);
            return 1;
        }
    }

    // pop remaining operators
    while (!isEmpty()) {
        if (peek() == '(' || peek() == ')') {
            printf("Error: mismatched parentheses\n");
            return 1;
        }
        postfix[k++] = pop();
        postfix[k++] = ' ';
    }

    // remove trailing space (if any) and null-terminate
    if (k > 0 && postfix[k-1] == ' ') k--;
    postfix[k] = '\0';

    printf("Postfix: %s\n", postfix);
    return 0;
}

