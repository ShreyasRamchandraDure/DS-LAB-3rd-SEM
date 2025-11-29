#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL, *head2 = NULL;

struct Node* createList() {
    int n, value;
    struct Node *head = NULL, *temp, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
}

struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* concatenate(struct Node *h1, struct Node *h2) {
    if (h1 == NULL) return h2;
    struct Node *temp = h1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = h2;
    return h1;
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Create List 1\n2.Create List 2\n3.Sort List 1\n4.Reverse List 1\n5.Concatenate Lists\n6.Display List 1\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head1 = createList(); break;
            case 2: head2 = createList(); break;
            case 3: sortList(head1); break;
            case 4: head1 = reverseList(head1); break;
            case 5: head1 = concatenate(head1, head2); break;
            case 6: display(head1); break;
            case 7: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
