//
// Created by luma on 31/08/24.
//

#include <cstack.h>
#include <stdlib.h>

stack *stack_init()
{
	return (calloc(1, sizeof(struct cstack)));
}

void stack_destroy(stack *s, void (*destructor)(void *))
{
	if (!s) return;
	if (destructor != NULL) {
		stack_clear(s, destructor);
	}
	free(s);
}

int stack_push(stack *s, void *data)
{
	if (!s) return -1;
	struct cstack_node *node = calloc(1, sizeof(struct cstack_node));
	if (!node) return -1;
	node->data = data;
	node->next = s->head;
	s->head = node;
	s->size++;
	return 0;
}

void *stack_pop(stack *s)
{
	if (!s || !s->head) return NULL;
	struct cstack_node *node = s->head;
	s->head = node->next;
	void *data = node->data;
	free(node);
	s->size--;
	return data;
}

void *stack_peek(stack *s)
{
	if (!s || !s->head) return NULL;
	return s->head->data;
}

bool stack_is_empty(stack *s)
{
	if (!s || !s->head) return false;
	return s->size == 0;
}

size_t stack_size(stack *s)
{
	if (!s || !s->head) return 0;
	return s->size;
}

void stack_clear(stack *s, void (*destructor)(void *))
{
	if (!s || !s->head) return;
	struct cstack_node *node = s->head;
	while (node) {
		struct cstack_node *next = node->next;
		destructor(node->data);
		free(node);
		node = next;
	}
	s->head = NULL;
	s->size = 0;
}
