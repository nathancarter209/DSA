// white a C code for liner queue ?
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int front;
    int rear;
    int size;
    int *arr;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    return queue;
}

void enqueue(Queue *queue, int data) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    queue->front++;
    int data = queue->arr[queue->front];
    queue->size--;
    return data;
}

int front(Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->arr[queue->front + 1];
}

int rear(Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->arr[queue->rear];
}

int isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

int main() {
    Queue *queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));       

    }