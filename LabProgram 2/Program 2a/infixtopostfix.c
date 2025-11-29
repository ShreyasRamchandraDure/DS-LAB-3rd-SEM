#include <stdio.h>
#include <ctype.h>   
#include <string.h>  

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1; 
    else
        return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char x;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        char symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while ((x = pop()) != '(')
                postfix[j++] = x;
        } else {
            while (precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

