#include "monty.h"
/**
 * add_to_stack - add element to stack
 * @new_node: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void add_to_stack(stack_t **new_node,unsigned int line__number)
{
	
	stack_t *tmp;
	(void)line__number;
	
	
	
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if(head == NULL)
	{
		
		head = *new_node;
		return;
	}

	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
	

}
