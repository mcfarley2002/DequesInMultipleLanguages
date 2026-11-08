#ifndef TYPED_QUEUE_H
#define TYPED_QUEUE_H

#include <stddef.h>
#include <stdlib.h>

/*
 * DEFINE_QUEUE(TYPE, NAME)
 *
 * Generates a queue type and a set of static functions for values of TYPE.
 *
 * Example:
 *
 *     DEFINE_QUEUE(int, IntQueue)
 *
 */

#define DEFINE_QUEUE(TYPE, NAME)                    \
    typedef struct NAME##_node                      \
    {                                               \
        TYPE value;                                 \
        struct NAME##_node *next;                   \
    } NAME##_node;                                  \
                                                    \
    typedef struct                                  \
    {                                               \
        NAME##_node *head;                          \
        NAME##_node *tail;                          \
    } NAME;                                         \
                                                    \
    static void NAME##_init(NAME *q)                \
    {                                               \
        q->head = NULL;                             \
        q->tail = NULL;                             \
    }                                               \
                                                    \
    static int NAME##_is_empty(const NAME *q)       \
    {                                               \
        return q->head == NULL;                     \
    }                                               \
                                                    \
    static void NAME##_enqueue(NAME *q, TYPE value) \
    {                                               \
        NAME##_node *node = malloc(sizeof(*node));  \
        if (node == NULL)                           \
            abort();                                \
                                                    \
        node->value = value;                        \
        node->next = NULL;                          \
                                                    \
        if (q->tail == NULL)                        \
            q->head = node;                         \
        else                                        \
            q->tail->next = node;                   \
                                                    \
        q->tail = node;                             \
    }                                               \
                                                    \
    static TYPE NAME##_dequeue(NAME *q)             \
    {                                               \
        if (NAME##_is_empty(q))                     \
            abort();                                \
                                                    \
        NAME##_node *old = q->head;                 \
        q->head = old->next;                        \
                                                    \
        TYPE data = old->value;                     \
        if (q->head == NULL)                        \
            q->tail = NULL;                         \
        free(old);                                  \
        return data;                                \
    }                                               \
                                                    \
    static void NAME##_destroy(NAME *q)             \
    {                                               \
        if (!q)                                     \
            return;                                 \
                                                    \
        while (!NAME##_is_empty(q))                 \
        {                                           \
            (void)NAME##_dequeue(q);                \
        }                                           \
    }

#endif