#include "monty.h"

stack_t *stk_head = NULL;

/**
 *main - the main function
 *@argc: argument counter
 *@argv: the arguements being passed aka the opcode files
 *Return: 0 is SUCCESS
 */

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		errors(1);

	open_file(argv[1]);
	free_stack(stk_head);
	return (0);
}

/**
 *open_file - funtion that open files (.m)
 *@file_name: files path
 *Return: void
 */

void open_file(char *file_name)
{
	FILE *monty_file;
	int file_exists;

	if (file_name == NULL)
	{
		errors(2, file_name);
	}

	file_exists = access(file_name, F_OK);
	if (file_exists == -1)
	{
		errors(2, file_name);
	}
	else
	{
		monty_file = fopen(file_name, "r");
		if (monty_file == NULL)
		{
			errors(2, file_name);
		}
		parse_file(monty_file);
		fclose(monty_file);
	}
}

/**
* new_node - Create a space in memory
* @n: int
* Return: pointer or NULL
*/

stack_t *new_node(int n)
{
    stack_t *node;
    /* here the data is saved in node */
    node = malloc(sizeof(stack_t));
    if (node == NULL)
        errors(6);
    node->next = NULL;
    node->prev = NULL;
    node->n = n;
    return (node);
}
