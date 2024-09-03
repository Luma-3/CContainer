#ifndef CSTACK_H
#define CSTACK_H

#include <stdbool.h>
#include <stddef.h>

struct cstack_node {
  void *data;
  struct cstack_node *next;
};

struct cstack
{
  size_t size;
  struct cstack_node *head;
};

typedef  struct cstack stack;

stack *stack_init() __attribute__((warn_unused_result));

void stack_destroy(stack *s, void (*destructor)(void *data));

int stack_push(stack *s, void *data) __attribute__((warn_unused_result));

void *stack_pop(stack *s);

void *stack_peek(stack *s);

bool stack_is_empty(stack *s);

size_t stack_size(stack *s);

void stack_clear(stack *s, void (*destructor)(void *data));

// TODO : reverse, toArray, clone, swap, duplicate, rotate, print, min/max

#endif //CSTACK_H
