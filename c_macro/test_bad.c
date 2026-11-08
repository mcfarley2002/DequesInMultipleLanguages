#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "typed_queue.h"

DEFINE_QUEUE(int, IntQueue)

int main(void) {
    IntQueue q;
    IntQueue_init(&q);

    for(int i = 0; i < 7; i++)
        IntQueue_enqueue(&q, i);

    char string[] = "hello";
    IntQueue_enqueue(&q, string);

    for(int j = 0; j < 8; j++){
        int data = IntQueue_dequeue(&q);
        printf("%dth number in queue: %d\n", j, data);
        assert(data == j);
    }

    IntQueue_destroy(&q);

    return 0;
}