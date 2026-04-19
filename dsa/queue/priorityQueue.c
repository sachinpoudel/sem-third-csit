#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int n = 0;

void enqueue(int value) {
    if (n == SIZE) {
        printf("Queue Overflow\n");
        return;
    }

    int i = n - 1;

    // shift elements to maintain priority order
    while (i >= 0 && queue[i] > value) {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1] = value;
    n++;
}

void dequeue() {
    if (n == 0) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[0]);

    for (int i = 1; i < n; i++) {
        queue[i - 1] = queue[i];
    }
    n--;
}