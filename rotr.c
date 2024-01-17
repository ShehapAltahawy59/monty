#include "monty.h"
/**
 * rotr - rotr to stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void rotr(stack_t **head, unsigned int none)
{
	stack_t *last,*first,*new_node,*pointer;
	(void)none;

	last = *head;
	first = *head;
	


	if (last == NULL)
	{
		return;
	}
	while(last->prev)
	{
		
		last = last->prev;
	}

	new_node = create_node(head);
	new_node->n = last->n;
	new_node->next = NULL;
	new_node->prev = *head;
	first->next = new_node;
	*head = new_node;
	pointer = last->next;
	pointer->prev = NULL;
	free(last);
	
	
}
