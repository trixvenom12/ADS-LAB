#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue() {
    int element;
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        printf("Queue is Full (Overflow)!\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &element);

    if (front == -1) { 
        front = rear = 0;
        queue[rear] = element;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0; 
        queue[rear] = element;
    } else {
        rear++;
        queue[rear] = element;
    }
    printf("Inserted %d successfully.\n", element);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty (Underflow)!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear) { 
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Circular Queue: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
