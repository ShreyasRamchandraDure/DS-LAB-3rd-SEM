#include <stdio.h>
#define limit 5

int front = -1, rear = -1, queue[limit], flag = 1;

void insert();
int del();
void display();

void main()
{
    int choice, x;

    while (1)
    {
        printf("\n1: Insert\n2: Display\n3: Delete\n4: Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                x = del();
                if (flag == 0)
                    printf("\nElement cannot be deleted");
                else
                    printf("\nDeleted element is %d", x);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!!!");
        }
    }
}

void insert()
{
    int item;

    if (rear == limit - 1)
    {
        printf("\nQUEUE OVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter element to be inserted: ");
        scanf("%d", &item);

        if (front == -1 && rear == -1)
            front = rear = 0;
        else
            rear++;

        queue[rear] = item;
        return;
    }
}

int del()
{
    int item;

    if (front == -1 && rear == -1)
    {
        printf("\nQUEUE IS EMPTY\n");
        flag = 0;
        return -1;
    }
    else
    {
        item = queue[front];

        if (front == rear)
            front = rear = -1;
        else
            front++;

        return item;
    }
}

void display()
{
    int i;

    if (front == -1 && rear == -1)
    {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }
    else
    {
        printf("\n");
        for (i = front; i <= rear; i++)
            printf(" %d", queue[i]);
    }
}
