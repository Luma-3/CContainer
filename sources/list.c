
#include <clist.h>

list *list_init()
{
	return (calloc(1, sizeof(struct clist)));
}

void list_destroy(list *l, void (*destructor)(void *data))
{
	if (l == NULL) return;

	list_clear(l, destructor);
	free(l);
}

int list_append(list *l, void *data)
{
	if (l == NULL) return -1;

	struct clist_node *new_node = calloc(1, sizeof(struct clist_node));
	if (new_node == NULL) return -1;

	new_node->data = data;

	if (l->head == NULL) {
		l->head = new_node;
		l->tail = new_node;
	} else {
		l->tail->next = new_node;
		l->tail = new_node;
	}

	l->size++;

	return 0;
}

int list_prepend(list *l, void *data)
{
	if (l == NULL) return -1;

	struct clist_node *new_node = calloc(1, sizeof(struct clist_node));
	if (new_node == NULL) return -1;

	new_node->data = data;

	if (l->head == NULL) {
		l->head = new_node;
		l->tail = new_node;
	} else {
		new_node->next = l->head;
		l->head = new_node;
	}

	l->size++;

	return 0;
}

int list_remove(list *l, void *data)
{
	if (l == NULL) return -1;

	struct clist_node *node = l->head;
	struct clist_node *prev = NULL;

	while (node != NULL) {
		if (node->data == data) {
			if (prev == NULL) {
				l->head = node->next;
			} else {
				prev->next = node->next;
			}

			if (node == l->tail) {
				l->tail = prev;
			}

			free(node);

			l->size--;

			return 0;
		}

		prev = node;
		node = node->next;
	}

	return -1;
}

bool list_is_empty(list *l)
{
	if (l == NULL || l->head == NULL) return false;

	return l->size == 0;
}

size_t list_size(list *l)
{
	if (l == NULL || l->head == NULL) return 0;

	return l->size;
}

void list_clear(list *l, void (*destructor)(void *data))
{
	if (l == NULL) return;

	struct clist_node *node = l->head;
	while (node != NULL) {
		struct clist_node *next = node->next;

		if (destructor != NULL) {
			destructor(node->data);
		}

		free(node);

		node = next;
	}

	l->size = 0;
	l->head = NULL;
	l->tail = NULL;
}