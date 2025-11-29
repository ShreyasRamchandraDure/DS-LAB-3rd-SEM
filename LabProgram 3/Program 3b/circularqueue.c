#include <stdio.h>
#define MAX 3

int queue[MAX];
int front=-1,rear=-1;

void insert() {
    int item;
    if ((front==0&&rear==MAX-1)||(rear+1)%MAX==front) {
        printf("Queue Overflow! Cannot insert more elements.\n");
    }else{
        printf("Enter the element to insert: ");
        scanf("%d", &item);
        if(front==-1) {
            front=0;
            rear=0;
        }else{
            rear=(rear+1)%MAX;
        }
        queue[rear]=item;
        printf("Inserted %d into the circular queue.\n", item);
    }
}

void delete(){
    if(front==-1){
        printf("Queue Underflow! Queue is empty.\n");
    }else{
        printf("Deleted element: %d\n",queue[front]);
        if(front==rear){
            front=rear=-1;
        }else{
            front=(front+1)% MAX;
        }
    }
}

void display() {
    if (front==-1) {
        printf("Queue is empty.\n");
    }else{
        int i=front;
        printf("Circular Queue elements are: ");
        while(1){
            printf("%d ",queue[i]);
            if (i==rear)
                break;
            i=(i+1)%MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice;

    printf("Enter: \n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    while(1){
        printf("Enter: \n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:insert(); break;
            case 2:delete(); break;
            case 3:display(); break;
            case 4:return 0;
            default:printf("Invalid choice!");
        }
    }
    return 0;
}
