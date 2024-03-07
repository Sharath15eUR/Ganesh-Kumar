#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->rear == -1);
}

int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        item = queue->items[queue->front];
        if (queue->front >= queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        return item;
    }
}

void sortQueue(struct Queue* queue) {
    int tempQueue[MAX_SIZE];
    int tempFront = queue->front;
    int tempRear = queue->rear;
    int tempIndex = 0;

    while (!isEmpty(queue)) {
        tempQueue[tempIndex++] = dequeue(queue);
    }

    for (int i = 1; i < tempIndex; i++) {
        int key = tempQueue[i];
        int j = i - 1;
        while (j >= 0 && tempQueue[j] > key) {
            tempQueue[j + 1] = tempQueue[j];
            j = j - 1;
        }
        tempQueue[j + 1] = key;
    }

    for (int i = 0; i < tempIndex; i++) {
        enqueue(queue, tempQueue[i]);
    }
}

void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    
    struct Queue* queue = createQueue();

    enqueue(queue, 4);
    enqueue(queue, 2);
    enqueue(queue, 7);
    enqueue(queue, 5);
    enqueue(queue, 1);

    printf("Original ");
    displayQueue(queue);

    sortQueue(queue);

    printf("Sorted ");
    displayQueue(queue);

    return 0;
}
