#ifndef CSTACK_H
#define CSTACK_H

#include <stdbool.h>
#include <stddef.h>

struct cstack_node {
	void			   *data;
	struct cstack_node *next;
};

struct cstack {
	size_t				size;
	struct cstack_node *head;
};

typedef struct cstack stack;

/**
 * @brief Initializes a new stack.
 *
 * @return A pointer to the new stack.
 * @return NULL if the stack could not be initialized.
 *
 * @note The returned stack must be freed using stack_destroy().
 */
stack *stack_init() __attribute__((warn_unused_result));

/**
 * @brief Destroys a stack.
 *
 * @param s The stack to destroy.
 * @param destructor A function pointer to a function that will be called on
 * each element in the stack.
 *
 * @note If the destructor is NULL, the elements will not be freed.
 */
void stack_destroy(stack *s, void (*destructor)(void *data));

/**
 * @brief Pushes an element onto the stack.
 *
 * @param s The stack to push the element onto.
 * @param data The element to push.
 *
 * @return 0 if the element was pushed successfully.
 * @return -1 if the element could not be pushed.
 *
 * @note data must be dynamically allocated.
 */
int stack_push(stack *s, void *data) __attribute__((warn_unused_result));

/**
 * @brief Pops an element from the stack.
 *
 * @param s The stack to pop the element from.
 *
 * @return A pointer to the popped element.
 */
void *stack_pop(stack *s);

/**
 * @brief Peeks at the top element of the stack.
 *
 * @param s The stack to peek at.
 *
 * @return A pointer to the top element.
 */
void *stack_peek(stack *s);

/**
 * @brief Checks if the stack is empty.
 *
 * @param s The stack to check.
 *
 * @return true if the stack is empty.
 * @return false if the stack is not empty.
 */
bool stack_is_empty(stack *s);

/**
 * @brief Gets the size of the stack.
 *
 * @param s The stack to get the size of.
 *
 * @return The size of the stack.
 */
size_t stack_size(stack *s);

/**
 * @brief Clears the stack.
 *
 * @param s The stack to clear.
 * @param destructor A function pointer to a function that will be called on
 * each element in the stack.
 *
 * @note If the destructor is NULL, the elements will not be freed.
 */
void stack_clear(stack *s, void (*destructor)(void *data));

// TODO : reverse, toArray, clone, swap, duplicate, rotate, print, min/max

#endif // CSTACK_H
