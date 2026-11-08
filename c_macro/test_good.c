#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "typed_queue.h"

DEFINE_QUEUE(int, IntQueue)

int main(void) {
    IntQueue q;
    IntQueue_init(&q);

    for(int i = 0; i < 8; i++)
        IntQueue_enqueue(&q, i);

    for(int j = 0; j < 8; j++){
        int data = IntQueue_dequeue(&q);
        printf("%dth number in queue: %d\n", j, data);
        assert(data == j);
    }

    IntQueue_destroy(&q);

    return 0;
}