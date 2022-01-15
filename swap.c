#include "monty.h"

/**
 *swap - function that swap's the elements in the stack
 *@stack: the head of the stack
 *@line_number: integer to insert
 *Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!*stack || !stack || !(*stack)->next)
		errors(5, line_number);

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
