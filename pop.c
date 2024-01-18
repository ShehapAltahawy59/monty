#include "monty.h"
/**
 * pop - return the head of stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void pop(stack_t **new_node,unsigned int line__number)
{
	stack_t *pointer;

	if (new_node == NULL || *new_node == NULL)
	{
		more_err(7, line_number);
	}
	pointer = *new_node;
	*new_node = pointer->next;
	if (*new_node != NULL)
		(*new_node)->prev = NULL;
	free(pointer);
}
