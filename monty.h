#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*global variable*/
stack_t **get_global_head(void);
void set_global_head(stack_t *new_head);

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);




/*operations of file*/
void open_file(char *f_name);
void read_file(FILE *);
int parse_line(char *buffer, int line_number, int format);
/* int len_characters(FILE *); */
void find_function(char *, char *, int, int);
void call_function(op_func, char *, char *, int, int);

/*operations of stack*/
stack_t *create_node(int n);
void free_all_nodes(void);
void add_node_stack(stack_t **, unsigned int);
void add_node_queue(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);




/*errors handling*/
void errors(int err_code, ...);

#endif /* MONTY_H */
