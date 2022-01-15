#include "monty.h"

/**
 *pall - print all in stack from top
 *@stack: structure with the stack of the element
 *@line_number: to push in the stack
 *Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp1 = *stack;
	while (tmp1 != NULL)
	{
		printf("%d\n", tmp1->n);
		tmp1 = tmp1->next;
	}
}
