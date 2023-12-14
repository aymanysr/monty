#include "monty.h"

stack_t *head = NULL;

stack_t **get_global_head(void)
{
  return &head;
}

void set_global_head(stack_t *new_head)
{
  head = new_head;
}
