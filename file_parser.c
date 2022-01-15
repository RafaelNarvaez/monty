#include "monty.h"

/**
 *parse_file - function that divides file in lines
 *@monty_file: the file to be cutted
 */

void parse_file(FILE *monty_file)
{
	int line_number;
	size_t buf = 0;
	int mode = 0;
	char *p_line = NULL;

	if (monty_file == NULL)
	{
		errors(2, monty_file);
	}
	/* move into the file */
	line_number = 1;
	while (getline(&p_line, &buf, monty_file) != EOF)
	{
		mode = parse_line(p_line, line_number, mode);
		line_number++;
	}
	free(p_line);
}

/**
 *parse_line - function that tokenize lines
 *@p_line: pointer to line
 *@line_number:integer
 *@mode: LIFO or FIFO
 *Return:the integer or mode
 */

int parse_line(char *p_line, int line_number, int mode)
{
	char *opcode;
	char *data;
	const char *separator;

	if (p_line == NULL)
		errors(6);

	separator = "\n ";
	/* 1st Token */
	opcode = strtok(p_line, separator);

	/* empty line */
	if (opcode == NULL)
		return (0);
	/* get next data */
	data = strtok(NULL, separator);
	/* selection */
		/* default selector */
	select_function(opcode, data, line_number, mode);
	return (mode);
}

/**
 *select_function - select a function to be use
 *@opcode: a pointer
 *@data: the info inside a node
 *@line_number: integer
 *@mode: FIFO and/or LIFO
 */

void select_function(char *opcode, char *data, int line_number, int mode)
{
	int idx;
	int nf;

	instruction_t functions[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall},
		{"swap", swap},
		{"nop", nop},
		{"pop", pop},
		{"add", add},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (idx = 0, nf = 1; functions[idx].opcode != NULL; idx++)
	{
		if (strcmp(opcode, functions[idx].opcode) == 0)
		{
			f_caller(functions[idx].f, opcode, data,
					line_number, mode);
			nf = 0;
		}
	}
	if (nf == 1)
	{
		more_errors(7, line_number, opcode);
	}
}

/**
 * f_caller - Execute function
 * @f: function
 * @opcode: char
 * @data: char
 * @line_number: int
 * @mode: FIFO or LIFO
 */
void f_caller(func f, char *opcode, char *data, int line_number, int mode)
{
	int i = 0;

	stack_t *node;

	if (strcmp(opcode, "push") == 0)
	{
		if (data == NULL)
			errors(1, line_number);

		while (data[i] != '\0')
		{
			if (isdigit(data[i]) == 0)
				errors(1, line_number);
			i++;
		}
		node = new_node(atoi(data));
		if (mode == 0)
		{
			f(&node, line_number);
		}
	}
	else
	{
		f(&stk_head, line_number);
	}
}
