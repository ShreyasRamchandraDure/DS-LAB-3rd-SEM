#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;


void push(int size) {
    int value;
    for (int i = 0; i < size; i++) {
        if (top == MAX_SIZE - 1) {
            printf("Stack Overflow! Stack is full.\n");
            break;
        }
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed onto stack.\n", value);
    }
}

void pop(int size) {
    for (int i = 0; i < size; i++) {
        if (top == -1) {
            printf("Stack Underflow! No elements to pop.\n");
            break;
        }
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty! No elements to display.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int size, choice;

    printf("Enter the size of the stack (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size. Exiting...\n");
        return -1;
    }

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push(size);
                break;
            case 2:
                pop(size);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

