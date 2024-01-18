#include "monty.h"
/**
 *sub - sub the top two element in stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void sub(stack_t **new_node,unsigned int line__number)
{
	int sub;

	if (new_node == NULL || *new_node == NULL || (*new_node)->next == NULL)
    {
		fprintf(stderr,"L%d: cant sub, stack too short\n",line__number);
		free_nodes();
		exit(EXIT_FAILURE);
	}


	(*new_node) = (*new_node)->next;
	sub = (*new_node)->n - (*new_node)->prev->n;
	(*new_node)->n = sub;
	free((*new_node)->prev);
	(*new_node)->prev = NULL;
}
