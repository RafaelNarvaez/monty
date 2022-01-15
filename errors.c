#include "monty.h"

/**
 * errors - Shows the errors
 * @error_code: code to select error
 * Return: Error
 */

void errors(int error_code, ...)
{
	va_list error_list;

	va_start(error_list, error_code);

	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: can't open file %s\n",
					va_arg(error_list, char *));
			break;
		case 3:
			fprintf(stderr, "L%d: usage: push integer\n",
					va_arg(error_list, int));
			break;
		case 4:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(error_list, int));
			break;
		case 5:
			fprintf(stderr, "L%d: can't swap, stack too short\n",
					va_arg(error_list, int));
			break;
		case 6:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
	va_end(error_list);
	exit(EXIT_FAILURE);
}

/**
 * more_errors - Shows erros acordingly to code
 * @error_code: code to select error to show
 * Return: Error
 *
 */

void more_errors(int error_code, ...)
{
	va_list error_list;
	int lin_n;
	char *err_c;

	va_start(error_list, error_code);

	switch (error_code)
	{
		case 7:
			lin_n = va_arg(error_list, int);
			err_c = va_arg(error_list, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n",
					lin_n, err_c);
			break;
		case 8:
			fprintf(stderr, "L%d: can't add, stack too short\n",
					va_arg(error_list, int));
			break;
		case 9:
			fprintf(stderr, "Error: can't pint, stack empty\n");
			break;
	}
	va_end(error_list);
	exit(EXIT_FAILURE);
}
