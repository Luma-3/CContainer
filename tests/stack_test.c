

#include <stdio.h>
#include <cstack.h>

int main() {
	// Create a new stack
	stack *s = stack_init();

	// Push some elements onto the stack
	int num1 = 10;
	int num2 = 20;
	int num3 = 30;
	stack_push(s, &num1);
	stack_push(s, &num2);
	stack_push(s, &num3);

	// Check the size of the stack
	printf("Stack size: %zu\n", stack_size(s));

	// Pop elements from the stack
	int *popped1 = stack_pop(s);
	int *popped2 = stack_pop(s);
	int *popped3 = stack_pop(s);

	// Print the popped elements
	printf("Popped elements: %d, %d, %d\n", *popped1, *popped2, *popped3);

	// Check if the stack is empty
	if (stack_is_empty(s)) {
		printf("Stack is empty\n");
	} else {
		printf("Stack is not empty\n");
	}

	// Clean up the stack
	stack_destroy(s, NULL);

	return 0;
}