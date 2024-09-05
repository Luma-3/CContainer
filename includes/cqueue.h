
#ifndef CQUEUE_H
#define CQUEUE_H

#include <stdbool.h>
#include <stdlib.h>

struct cqueue_node {
	void			   *data;
	struct cqueue_node *next;
};

struct cqueue {
	size_t				size;
	struct cqueue_node *head;
	struct cqueue_node *tail;
};

typedef struct cqueue queue;

/**
 * @brief Initializes a new queue.
 *
 * @return A pointer to the new queue.
 * @return NULL if the queue could not be initialized.
 *
 * @note The returned queue must be freed using queue_destroy().
 */
queue *queue_init() __attribute__((warn_unused_result));

/**
 * @brief Destroys a queue.
 *
 * @param q The queue to destroy.
 * @param destructor A function pointer to a function that will be called on
 * each element in the queue.
 *
 * @note If the destructor is NULL, the elements will not be freed.
 */
void queue_destroy(queue *q, void (*destructor)(void *data));

/**
 * @brief Enqueues an element in the queue.
 *
 * @param q The queue to enqueue the element in.
 * @param data The element to enqueue.
 *
 * @return 0 if the element was enqueued successfully.
 * @return -1 if the element could not be enqueued.
 *
 * @note data must be dynamically allocated.
 */
int queue_enqueue(queue *q, void *data) __attribute__((warn_unused_result));

/**
 * @brief Dequeues an element from the queue.
 *
 * @param q The queue to dequeue the element from.
 *
 * @return A pointer to the dequeued element.
 * @return NULL if the element could not be dequeued.
 */
void *queue_dequeue(queue *q);

/**
 * @brief Peeks at the element at the front of the queue.
 *
 * @param q The queue to peek at.
 *
 * @return A pointer to the element at the front of the queue.
 * @return NULL if the queue is empty.
 */
void *queue_peek(queue *q);

/**
 * @brief Checks if the queue is empty.
 *
 * @param q The queue to check.
 *
 * @return true if the queue is empty.
 * @return false if the queue is not empty.
 *
 * @note If q is NULL, false is returned.
 */
bool queue_is_empty(queue *q);

/**
 * @brief Returns the size of the queue.
 *
 * @param q The queue to get the size of.
 *
 * @return The size of the queue.
 * @return 0 if the queue is empty.
 *
 * @note If q is NULL, 0 is returned.
 */
size_t queue_size(queue *q);

/**
 * @brief Clears the queue.
 *
 * @param q The queue to clear.
 * @param destructor A function pointer to a function that will be called on
 * each element in the queue.
 *
 * @note If the destructor is NULL, the elements will not be freed.
 */
void queue_clear(queue *q, void (*destructor)(void *data));

#endif // CQUEUE_H