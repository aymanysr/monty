#include "monty.h"
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success always
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);
	free_all_nodes();
	return (0);
}

/**
 * create_node - A function that creates a node.
 * @n: Number to go inside the node.
 * Return: A pointer to the node upon sucess . Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errors(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_all_nodes - Frees the nodes existing in the stack.
 */
void free_all_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_node_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @line_number: line number of the opcode.
 */
void add_node_queue(stack_t **new_node, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}

/**
 * add_node_stack - Adds a node to the stack.
 * @new_node: Pointer to new node.
 * @line_number: Int representing the line num of of the opcode.
 */
void add_node_stack(stack_t **new_node, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}
