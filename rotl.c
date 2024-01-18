#include "monty.h"
/**
 * rotl - rotl to stack
 * @new_node: pointer of pointer to head of stack
 * @none: the line which is excuted
 * Return:void
*/
void rotl(stack_t **new_node, unsigned int none)
{
	
	stack_t *pointer;
	
	(void)none;
	if (new_node == NULL || *new_node == NULL || (*new_node)->next == NULL)
		return;
	pointer = *new_node;
	while (pointer->next != NULL)
		pointer = pointer->next;
	pointer->next = *new_node;
	(*new_node)->prev = pointer;
	*new_node = (*new_node)->next;
	(*new_node)->prev->next = NULL;
	(*new_node)->prev = NULL;
}
