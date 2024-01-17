#include "monty.h"
/**
 * mod_ - mod the top two element in stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void mod_(stack_t **head,unsigned int line__number)
{
	stack_t *pointer;
	int sum;
	pointer = *head;
	
	if(pointer ==NULL || pointer->prev == NULL)
	{
		free_nodes(head);
		fprintf(stderr,"L%d: cant mod, stack too short\n",line__number);
		exit(EXIT_FAILURE);
		
	}
	if ((*head)->n == 0)
	{
	 fprintf(stderr,"L%d: division by zero\n",line__number);
	 free_nodes(head);
	 exit(EXIT_FAILURE);
	}
	else
	{
		
		pointer = (*head)->prev;
		sum = (pointer->n) % (*head)->n;
		pointer->n = sum;
		free(*head);
		*head = pointer;
	}
}
