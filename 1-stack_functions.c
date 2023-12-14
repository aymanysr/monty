#include "monty.h"

/**
 * print_stack - prints the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
*/
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
