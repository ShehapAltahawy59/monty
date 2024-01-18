#include "monty.h"
/**
 * add - add top two element in stack
 * @new_node: pointer of pointer to head of stack
 * @line__number: the line which is excuted
 * Return:void
*/

void add(stack_t **new_node, unsigned int line__number)
{
	int sum;

	if (new_node == NULL || *new_node == NULL || (*new_node)->next == NULL)
	{
		more_err(8, line__number, "add");
	}

	(*new_node) = (*new_node)->next;
	sum = (*new_node)->n + (*new_node)->prev->n;
	(*new_node)->n = sum;
	free((*new_node)->prev);
	(*new_node)->prev = NULL;
}
