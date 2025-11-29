#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            struct Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void insertFirst(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertPos(int val, int pos) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst() {
    if (head == NULL) return;

    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteLast() {
    if (head == NULL) return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void deleteValue(int val) {
    if (head == NULL) return;

    if (head->data == val) {
        struct Node *t = head;
        head = head->next;
        free(t);
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != val)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Value not found\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = temp->next->next;
    free(del);
}

void display() {
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n1.Create 2.Insert First 3.Insert End 4.Insert Pos\n");
        printf("5.Delete First 6.Delete Last 7.Delete Value 8.Display 9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: printf("Value: "); scanf("%d", &val); insertFirst(val); break;
            case 3: printf("Value: "); scanf("%d", &val); insertEnd(val); break;
            case 4: printf("Value & Position: "); scanf("%d%d", &val,&pos); insertPos(val,pos); break;
            case 5: deleteFirst(); break;
            case 6: deleteLast(); break;
            case 7: printf("Value: "); scanf("%d",&val); deleteValue(val); break;
            case 8: display(); break;
            case 9: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
