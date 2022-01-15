#include "monty.h"

/**
 *push - function that insert an element to a stack
 *@stack: structure with the stack of the element
 *@line_number: to push in the stack
 *Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node_to_stack;

	(void) line_number;
	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	/* EMPTY HEAD */
	if (stk_head == NULL)
	{
		stk_head = *stack;
		return;
	}
	node_to_stack = stk_head;
	stk_head = *stack;
	stk_head->next = node_to_stack;
	node_to_stack->prev = stk_head;
}
