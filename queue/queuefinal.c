#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10000

struct Queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue* queue, int item, FILE* enqueue_log_file) {
    if ((queue->rear + 1) % QUEUE_SIZE == queue->front) {
        printf("Queue overflow! Skipping enqueue of %d.\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->items[queue->rear] = item;
    fprintf(enqueue_log_file, "Enqueued %d into the queue.\n", item);
}

int dequeue(struct Queue* queue, FILE* dequeue_log_file) {
    if (queue->front == queue->rear) {
        printf("Queue underflow!\n");
        return -1;
    }
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    int item = queue->items[queue->front];
    fprintf(dequeue_log_file, "Dequeued %d from the queue.\n", item);
    return item;
}

int main() {
    struct Queue queue;
    queue.front = 0;
    queue.rear = 0;

    FILE* random_file = fopen("random.txt", "r");
    FILE* enqueue_log_file = fopen("enqueue.txt", "w");
    FILE* dequeue_log_file = fopen("dequeue.txt", "w");
    FILE* operation_log_file = fopen("queueoperation.txt", "w");

    if (random_file == NULL || enqueue_log_file == NULL || dequeue_log_file == NULL || operation_log_file == NULL) {
        printf("Error opening files!\n");
        exit(1);
    }

    int number;
    while (fscanf(random_file, "%d", &number) == 1) {
        enqueue(&queue, number, enqueue_log_file);
        fprintf(operation_log_file, "Enqueued %d into the queue.\n", number);
    }

    while (queue.front != queue.rear) {
        int item = dequeue(&queue, dequeue_log_file);
        fprintf(operation_log_file, "Dequeued %d from the queue.\n", item);
    }

    fclose(random_file);
    fclose(enqueue_log_file);
    fclose(dequeue_log_file);
    fclose(operation_log_file);

    return 0;
}
