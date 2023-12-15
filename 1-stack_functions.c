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

/**
 * print_top_stack - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top_stack(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_errors(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * pop_top_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 * Return: Void.
 */
void pop_top_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *next_node;

	if (!stack || !*stack)
	{
		more_errors(7, line_number);
		exit(EXIT_FAILURE);
	}

	next_node = (*stack)->next;
	free(*stack);
	*stack = next_node;
}
