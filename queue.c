#include <stdio.h>
#include <stdlib.h>

int *queue;
int N;
int front = -1;
int rear = -1;

void enqueue() {
    int ele;
    printf("Enter the element to be enqueued: ");
    scanf("%d", &ele);

    if ((rear + 1) % N == front) {
        printf("Overflow! Queue is full.\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = ele;
        printf("Inserted %d successfully.\n", ele);
    } else {
        rear = (rear + 1) % N;
        queue[rear] = ele;
        printf("Inserted %d successfully.\n", ele);
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow! Queue is empty.\n");
    } else if (front == rear) {
        printf("Dequeued element: %d\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % N;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    
    printf("Enter the size of the circular queue: ");
    scanf("%d", &N);

    // Prevent division/modulo by zero and invalid allocations
    if (N <= 0) {
        printf("Invalid size! Size must be greater than 0.\n");
        return 1;
    }

    queue = (int *)malloc(N * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

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
                free(queue);
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    
    return 0;
}
