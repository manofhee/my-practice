#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define QUEUE_COUNT 100

typedef struct {
    int data[QUEUE_COUNT];
    int head;
    int tail;
} Queue;

int queue_inc(int index) {
    return (index + 1) % QUEUE_COUNT;
}

void queue_init(Queue* q) {
    q->head = q->tail = 0;
}

bool queue_is_empty(Queue* q) {
    return q->head == q->tail;
}

bool queue_is_full(Queue* q) {
    return queue_inc(q->head) == q->tail;
}

bool queue_push(Queue* q, int val) {
    if(queue_is_full(q)) {
        printf("queue_push failed due to queue full\n");
        return false;
    }
    q->head = queue_inc(q->head);
    q->data[q->head] = val;
    return true;
}

bool queue_pop(Queue* q, int* pval) {
    if(queue_is_empty(q)) {
        printf("queue_pop failed due to queue empty\n");
        return false;
    }
    *pval = q->data[q->tail];
    q->tail = queue_inc(q->tail);
    return true;
}

int queue_used(Queue* q) {
    return ((q->head + QUEUE_COUNT) - q->tail) % QUEUE_COUNT;
}