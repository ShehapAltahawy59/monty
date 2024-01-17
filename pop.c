#include "monty.h"
/**
 * pop - return the head of stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void pop(stack_t **head,unsigned int line__number)
{
	stack_t *pointer;
	(void)line__number;

	if (*head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line__number);
		free_nodes(head);
		exit(EXIT_FAILURE);
	}
	
	pointer = *head;
	printf("%d\n", (*head)->n);
	(*head) = (*head)->prev;
	free(pointer);
	
}
