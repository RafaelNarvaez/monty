#include "monty.h"

/**
 *pop - pop's out the top element of the stack
 *@stack: structure with the stack of the element
 *@line_number: to push in the stack
 *Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!stack || !*stack)
		errors(4, line_number);

	*stack = current->next;
	if (current->next)
		current->next->prev = NULL;
	free(current);
}
