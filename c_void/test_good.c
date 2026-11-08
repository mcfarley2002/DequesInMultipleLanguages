#include <assert.h>
#include <stdio.h>
#include "queue.h"

int main()
{
    Queue *q = queue_create();

    assert(q != NULL);
    assert(queue_is_empty(q) == 1);

    int values[] = {199, 42, 14, 37, 22, 90, 8};

    for (int i = 0; i < 7; i++)
        queue_enqueue(q, &values[i]);

    for (int i = 0; i < 6; i++)
    {
        int *x = (int *)queue_dequeue(q);
        printf("dequeued value: %d\n", *x);
        assert(*x == values[i]);
    }

    int *last = (int *)queue_dequeue(q);
    printf("last value: %d\n", *last);
    assert(*last == values[6]);

    assert(queue_is_empty(q) == 1);

    queue_destroy(q);
    return 0;
}