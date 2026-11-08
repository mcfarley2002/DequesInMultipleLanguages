#include <stddef.h>
#include <stdlib.h>
#include "queue.h"

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

struct queue {
    Node *head;
    Node *tail;
};

Queue *queue_create(void){
    Queue *q = malloc(sizeof(Queue));

    if(!q) return NULL;

    q->head = NULL;
    q->tail = NULL;
    return q;
}

void queue_enqueue(Queue *q, void *item){
    if(!q) return;

    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->data = item;
    newNode->next = NULL;

    if(q->head == NULL){
        q->head = newNode;
        q->tail = newNode;
    }
    else{
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

void *queue_dequeue(Queue *q){
    if(!q || queue_is_empty(q)) return NULL;

    Node *temp = q->head;
    void *item = temp->data;
        q->head = q->head->next;

    if(q->head == NULL) q->tail = NULL;

    free(temp);
    return item;
}

int queue_is_empty(Queue *q){
    if(!q) return 1;
    return q->head == NULL;
}

void queue_destroy(Queue *q){
    if(!q) return;

    Node *curr = q->head;

    while(curr != NULL){
        Node *nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }

    free(q);
}