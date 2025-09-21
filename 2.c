#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = x;
}


int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': {
            int result = 1;
            for (int i = 0; i < b; i++) result *= a;
            return result;
        }
        default: return 0;
    }
}


int evaluatePrefix(char* prefix) {
    int n = strlen(prefix);

    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isspace(c)) continue; 

        if (isdigit(c)) {
            push(c - '0'); 
        }
        else if (isOperator(c)) {
            int op1 = pop();
            int op2 = pop();
            int result = applyOp(op1, op2, c);
            push(result);
        }
    }

    return pop();
}

int main() {
    char prefix[MAX];

    printf("Enter a prefix expression: ");
    fgets(prefix, MAX, stdin);

    int result = evaluatePrefix(prefix);
    printf("Result: %d\n", result);

    return 0;
}

