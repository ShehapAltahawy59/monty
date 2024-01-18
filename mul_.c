#include "monty.h"
/**
 * mul_ - mul the top two element in stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void mul_(stack_t **new_node,unsigned int line__number)
{
	int result;

	if (new_node == NULL || *new_node == NULL || (*new_node)->next == NULL)
	{
		fprintf(stderr,"L%d: cant mul, stack too short\n",line__number);
		free_nodes();
		exit(EXIT_FAILURE);
	}

	(*new_node) = (*new_node)->next;
	result = (*new_node)->n * (*new_node)->prev->n;
	(*new_node)->n = result;
	free((*new_node)->prev);
	(*new_node)->prev = NULL;
}
