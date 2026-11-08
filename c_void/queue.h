#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue *queue_create(void);
void queue_enqueue(Queue *q, void *item);
void *queue_dequeue(Queue *q);
int queue_is_empty(Queue *q);
void queue_destroy(Queue *q);

#endif