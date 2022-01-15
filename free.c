#include "monty.h"

/**
 * free_stack - frees the stack
 * @stk_head: head to refer
 */

void free_stack(stack_t *stk_head)
{
	stack_t *tmp1;

	if (stk_head == NULL)
		return;

	while (stk_head != NULL)
	{
		tmp1 = stk_head;
		stk_head = stk_head->next;
		free(tmp1);
	}
}
