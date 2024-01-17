#include "monty.h"
/**
 *sub - sub the top two element in stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void sub(stack_t **head,unsigned int line__number)
{
	stack_t *pointer;
	int sum;
	pointer = *head;
	
	if(pointer == NULL || pointer->prev == NULL)
	{
		fprintf(stderr,"L%d: cant sub, stack too short\n",line__number);
		free_nodes(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		
		pointer = (*head)->prev;
		sum = (*head)->n - (pointer->n) ;
		pointer->n = sum;
		free(*head);
		*head = pointer;
	}
}
