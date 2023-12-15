#include "monty.h"

stack_t *head = NULL;

/**
 * get_global_head - returns the global head
 * Return: the global head
*/
stack_t **get_global_head(void)
{
	return (&head);
}

/**
 * set_global_head - sets the global head
 * @new_head: the new head
 * Return: void
*/
void set_global_head(stack_t *new_head)
{
	head = new_head;
}
