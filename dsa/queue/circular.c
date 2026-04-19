#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted: %d\n", queue[front]);

        if (front == rear) {
            front = rear = -1; // queue empty
        } else {
            front = (front + 1) % SIZE;
        }
    }
}