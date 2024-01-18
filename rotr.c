#include "monty.h"
/**
 * rotr - rotr to stack
 * @new_node: pointer of pointer to head of stack
 * @none: the line which is excuted
 * Return:void
*/
void rotr(stack_t **new_node, unsigned int none)
{
	stack_t *pointer;
	
	(void)none;
	if (new_node == NULL || *new_node == NULL || (*new_node)->next == NULL)
		return;
	pointer = *new_node;
	while (pointer->next != NULL)
		pointer = pointer->next;
	pointer->next = *new_node;
	pointer->prev->next = NULL;
	pointer->prev = NULL;
	(*new_node)->prev = pointer;
	(*new_node) = pointer;
}
