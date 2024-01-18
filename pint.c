#include "monty.h"
/**
 * pint - print the head of stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void pint(stack_t **new_node,unsigned int line__number)
{
    if (new_node == NULL || *new_node == NULL)
	{
		more_err(6, line__number);
	}
	printf("%d\n", (*new_node)->n);
	
}
