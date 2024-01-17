#include "monty.h"
/**
 * add - add top two element in stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/

void add(stack_t **head,unsigned int line__number)
{
	stack_t *pointer;
	int sum;
	pointer = *head;
	
	if(pointer->prev == NULL)
	{
		printf("L%d: cant add, stack too short\n",line__number);
		free_nodes(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		
		pointer = (*head)->prev;
		sum = (pointer->n) + (*head)->n ;
		pointer->n = sum;
		free(*head);
		*head = pointer;
	}
}
