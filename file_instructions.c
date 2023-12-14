#include "monty.h"

/**
 * open_file - opens a file
 * @f_name: namepath of file to open
 * Return: void
 */

void open_file(char *f_name)
{
	FILE *file = fopen(f_name, "r");

	if (f_name == NULL || file == NULL)
		errors(2, f_name);

	read_file(file);
	fclose(file);
}

/**
 * read_file - reads a file
 * @file: pointer to the file to read
 * Return: void
 */

void read_file(FILE *file)
{
	int line_number;
	int format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_number = 1; getline(&buffer, &length, file) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}

/**
 * parse_line - parses a line
 * @buffer: line to parse
 * @line_number: line number
 * @format: format of the line, nodes will enter as a stack if 0, queue if 1
 * Return: format of the line
*/

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *delimiter = "\t\n ";

	if (buffer == NULL)
		errors(4);

	opcode = strtok(buffer, delimiter);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, val, line_number, format);
	return (format);
}

/**
 * find_function - finds the function to execute
 * @opcode: opcode to find
 * @val: value to pass to the function
 * @line_number: line number
 * @format: format of the line, nodes will enter as a stack if 0, queue if 1
 * Return: void
*/
void find_function(char *opcode, char *val, int line_number, int format)
{
	int i;
	int flag;

	instruction_t functions_list[] = {
		{"push", add_node_stack},
		{"pall", print_stack},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; functions_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, functions_list[i].opcode) == 0)
		{
			call_function(functions_list[i].f, opcode, val, line_number, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, line_number, opcode);
}

/**
 * call_function - calls the function to execute
 * @func: function to call
 * @op: opcode
 * @val: value to pass to the function
 * @line_num: line number
 * @format: format of the line, nodes will enter as a stack if 0, queue if 1
 * Return: void
*/

void call_function(op_func func, char *op, char *val, int line_num, int format)
{
	stack_t **node_ptr = get_global_head();
	stack_t *node = *node_ptr;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errors(5, line_num);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errors(5, line_num);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, line_num);
		if (format == 1)
			add_node_queue(&node, line_num);
		set_global_head(node);
	}
	else
		func(&node, line_num);
}
