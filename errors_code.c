#include "monty.h"
/**
 * errors - prints error messages according to their error code
 * @err_code: error codes are:
 * 1 - usage: at least 1 monty file doesn't exist
 * 2 - Error: Can't open nor read file <file>
 * 3 - Error: file contains invalid instruction <opcode>
 * 4 - Error: file unable to malloc anymore
 * 5 - Error: param passed to instruction 'push' is not an int
 * 6 - Error: can't pint an empty stack
 * 7 - Error: can't pop an empty stack
 * 8 - Error: stack too short
*/
void errors(int err_code, ...)
{
	va_list args;
	int line_number;
	char *opcode;

	va_start(args, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			line_number = va_arg(args, int);
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
	free_all_nodes();
	exit(EXIT_FAILURE);
}
