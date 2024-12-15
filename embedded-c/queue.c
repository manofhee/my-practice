#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define QUEUE_COUNT 10

typedef struct
{
    int item[QUEUE_COUNT];
    int head;
    int tail;
} Queue;

int queue_inx_inc(int val)
{
    return (val + 1) % QUEUE_COUNT;
}

void queue_init(Queue *q)
{
    q->head = q->tail = 0;
}

bool queue_is_empty(Queue *q)
{
    return q->head == q->tail;
}

bool queue_is_full(Queue *q)
{
    return queue_inx_inc(q->head) == q->tail;
}

bool queue_push(Queue *q, int val)
{
    if (queue_is_full(q)) {
        printf("queue push fail, queue full\n");
        return false;
    }
    q->head = queue_inx_inc(q->head);
    q->item[q->head] = val;
    return true;
}

bool queue_pop(Queue *q, int *val)
{
    if (queue_is_empty(q)) {
        printf("queue pop fail, queue empty\n");
        return false;
    }
    *val = q->item[q->tail];
    q->tail = queue_inx_inc(q->tail);
    return true;
}
