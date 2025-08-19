#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
    }
}

// Find max element in queue
void findMax() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    int max = queue[front];
    for (int i = front + 1; i <= rear; i++) {
        if (queue[i] > max)
            max = queue[i];
    }

    printf("Maximum element in the queue: %d\n", max);
}

// Display queue
void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, value;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    displayQueue();
    findMax();

    return 0;
}

