#include "monty.h"
/**
 * pint - print the head of stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void pint(stack_t **head,unsigned int line__number)
{
	stack_t *pointer;

	pointer = *head;
	
	if(pointer == NULL)
	{
		fprintf(stderr,"L%d: can't pint, stack empty\n",line__number);
		free_nodes(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		
		fprintf(stdout,"%d\n", pointer->n);
	}
}
