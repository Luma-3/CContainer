
#include <cqueue.h>

queue *queue_init()
{
	return (calloc(1, sizeof(struct cqueue)));
}

void queue_destroy(queue *q, void (*destructor)(void *data))
{
	if (q == NULL) return;

	queue_clear(q, destructor);
	free(q);
}

int queue_enqueue(queue *q, void *data)
{
	if (q == NULL) return -1;

	struct cqueue_node *new_node = calloc(1, sizeof(struct cqueue_node));
	if (new_node == NULL) return -1;

	new_node->data = data;

	if (q->head == NULL) {
		q->head = new_node;
		q->tail = new_node;
	} else {
		q->tail->next = new_node;
		q->tail = new_node;
	}

	q->size++;

	return 0;
}

void *queue_dequeue(queue *q)
{
	if (q == NULL || q->head == NULL) return NULL;

	struct cqueue_node *node = q->head;
	void			   *data = node->data;

	q->head = node->next;
	q->size--;

	free(node);

	return data;
}

void *queue_peek(queue *q)
{
	if (q == NULL || q->head == NULL) return NULL;

	return q->head->data;
}

bool queue_is_empty(queue *q)
{
	if (q == NULL || q->head == NULL) return false;

	return q->size == 0;
}

size_t queue_size(queue *q)
{
	if (q == NULL || q->head == NULL) return 0;

	return q->size;
}

void queue_clear(queue *q, void (*destructor)(void *data))
{
	if (q == NULL || q->head == NULL) return;

	struct cqueue_node *node = q->head;
	while (node) {
		struct cqueue_node *next = node->next;
		destructor(node->data);
		free(node);
		node = next;
	}

	q->head = NULL;
}
