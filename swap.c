#include "monty.h"
/**
 * swap - swap the top two element in stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void swap(stack_t **new_node,unsigned int line__number)
{
	stack_t *pointer;

	if (new_node == NULL || *new_node == NULL || (*new_node)->next == NULL)
	{
		fprintf(stderr,"L%d: can't swap, stack too short\n",line__number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	pointer = (*new_node)->next;
	(*new_node)->next = pointer->next;
	if (pointer->next != NULL)
		pointer->next->prev = *new_node;
	pointer->next = *new_node;
	(*new_node)->prev = pointer;
	pointer->prev = NULL;
	*new_node = pointer;
}
