#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

void displayStack(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}


void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = createNode(value);

    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }

    struct Node* temp = *front;
    int value = temp->data;
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
    return value;
}

void displayQueue(struct Node* front) {
    printf("Queue: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *stack = NULL;
    struct Node *front = NULL, *rear = NULL;

    int choice, value, n, i;

    while (1) {
        printf("\n==== MENU ====\n");
        printf("1. Push multiple values (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue multiple values (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("How many values to push? ");
                scanf("%d", &n);
                printf("Enter %d values:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &value);
                    push(&stack, value);
                }
                break;

            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;

            case 3:
                displayStack(stack);
                break;

            case 4:
                printf("How many values to enqueue? ");
                scanf("%d", &n);
                printf("Enter %d values:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &value);
                    enqueue(&front, &rear, value);
                }
                break;

            case 5:
                value = dequeue(&front, &rear);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;

            case 6:
                displayQueue(front);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}