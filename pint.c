#include "monty.h"

/**
 *pint - prints the top of the stack
 *@stack: header of stack
 *@line_number: integer to insert
 *Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
		more_errors(9, line_number);
	printf("%d\n", (*stack)->n);
}
