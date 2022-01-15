#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Number to push in the stack.
 * Return: void.
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number);

	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(current);
}
