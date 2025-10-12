#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow.\n");
    } else {
        top++;
        stack[top] = item;
    }
}

char pop() {
    char item;
    if (top < 0) {
        printf("Stack Underflow.\n");
        return ' ';
    } else {
        item = stack[top];
        top--;
        return item;
    }
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0;
    int j = 0;
    char item;
    char x;

    push('(');
    strcat(infix, ")");

    item = infix[i];

    while (item != '\0') {
        if (item == '(') {
            push(item);
        } else if (isalnum(item)) {
            postfix[j] = item;
            j++;
        } else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix[j] = x;
                j++;
                x = pop();
            }
        } else {
            while (precedence(stack[top]) >= precedence(item)) {
                postfix[j] = pop();
                j++;
            }
            push(item);
        }
        i++;
        item = infix[i];
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("INFIX TO POSTFIX CONVERSION\n");
    printf("============================\n");
    printf("Supported Operators: +, -, *, /, %%, ^\n");
    printf("Enter a valid Infix expression: ");
    
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\nInfix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}