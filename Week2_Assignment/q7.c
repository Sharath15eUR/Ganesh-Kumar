// #include <stdio.h>
// #include <stdlib.h>

// // Define queue structure
// #define MAX_SIZE 100

// typedef struct {
//     int data[MAX_SIZE];
//     int front, rear;
// } Queue;

// // Function to initialize the queue
// void initialize(Queue *queue) {
//     queue->front = -1;
//     queue->rear = -1;
// }

// // Function to check if the queue is empty
// int isEmpty(Queue *queue) {
//     return queue->front == -1;
// }

// // Function to check if the queue is full
// int isFull(Queue *queue) {
//     return (queue->rear + 1) % MAX_SIZE == queue->front;
// }

// // Function to insert an element into the queue
// void enqueue(Queue *queue, int value) {
//     if (isFull(queue)) {
//         printf("Queue Overflow\n");
//         return;
//     }
//     if (isEmpty(queue)) {
//         queue->front = 0;
//         queue->rear = 0;
//     } else {
//         queue->rear = (queue->rear + 1) % MAX_SIZE;
//     }
//     queue->data[queue->rear] = value;
// }

// // Function to remove an element from the queue
// int dequeue(Queue *queue) {
//     if (isEmpty(queue)) {
//         printf("Queue Underflow\n");
//         exit(1);
//     }
//     int value = queue->data[queue->front];
//     if (queue->front == queue->rear) {
//         queue->front = -1;
//         queue->rear = -1;
//     } else {
//         queue->front = (queue->front + 1) % MAX_SIZE;
//     }
//     return value;
// }

// // Function to count the number of elements in the queue
// int countElements(Queue *queue) {
//     if (isEmpty(queue)) {
//         return 0;
//     }
//     return (queue->rear - queue->front + MAX_SIZE) % MAX_SIZE + 1;
// }

// // Function to display the elements of the queue
// void display(Queue *queue) {
//     if (isEmpty(queue)) {
//         printf("Queue is empty\n");
//         return;
//     }
//     printf("Queue elements are: ");
//     int i = queue->front;
//     do {
//         printf("%d ", queue->data[i]);
//         i = (i + 1) % MAX_SIZE;
//     } while (i != (queue->rear + 1) % MAX_SIZE);
//     printf("\n");
// }

// int main() {
//     Queue queue;
//     initialize(&queue);

//     printf("Initialize a queue!\n");

//     if (isEmpty(&queue)) {
//         printf("Check the queue is empty or not? Yes\n");
//     } else {
//         printf("Check the queue is empty or not? No\n");
//     }

//     printf("Number of elements in queue: %d\n", countElements(&queue));

//     printf("\nInsert some elements into the queue:\n");
//     enqueue(&queue, 1);
//     enqueue(&queue, 2);
//     enqueue(&queue, 3);
//     display(&queue);
//     printf("Number of elements in queue: %d\n", countElements(&queue));

//     printf("\nDelete two elements from the said queue:\n");
//     dequeue(&queue);
//     dequeue(&queue);
//     display(&queue);
//     printf("Number of elements in queue: %d\n", countElements(&queue));

//     printf("\nInsert another element into the queue:\n");
//     enqueue(&queue, 4);
//     display(&queue);
//     printf("Number of elements in the queue: %d\n", countElements(&queue));

//     return 0;
// }
#include <stdio.h>
#include <string.h>
#define size 10

int queue[size];
int front = -1, rear = -1;

void enqueue(int elem) {
    if (front == size - 1) {
        printf("Queue Overflow!\n");
    } else {
        rear++;
        queue[rear] = elem;
        if (front == -1) {
            front = 0;
        }
    }
}

void dequeue() {
    if (front > rear) {
        printf("Queue underflow!\n");
    } else {
        // printf("Dequeued\n");
        front++;
    }
}

void display() {
    if (front > rear || front == -1) {
        printf("Queue is empty!\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void count() {
    if (front > rear || front == -1) {
        printf("Number of elements in queue: 0\n");
    } else {
        int count = rear - front + 1;
        printf("Number of elements in queue: %d\n", count);
    }
}

int main() {
    char ch[3];

    printf("Initialize a queue!\n");

    printf("Check the queue is empty or not? ");
    scanf("%s",&ch);
    if(strcmp(ch, "yes") == 0)
     {   count();   }

    printf("Insert some elements into the queue:\nQueue elements are: ");
    for(int i=0;i<3;i++){
        int elem;
        scanf("%d", &elem);
        enqueue(elem);
    }
    count();

    printf("Delete two elements from the said queue:\nQueue elements are: ");
    dequeue();
    dequeue();
    display();
    count();

    printf("Insert another element into the queue:\nQueue elements are: ");
    enqueue(4);
    display();
    count();
    
    return 0;
}
