#include "monty.h"
/**
 * pchar - print the top as char 
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void pchar(stack_t **new_node,unsigned int line__number)
{
    
	int ascii;

	if (new_node == NULL || *new_node == NULL)
	{
		fprintf(stderr,"L%d: can't pchar, stack empty\n",line__number);
		free_nodes();
		exit(EXIT_FAILURE);
	}

	ascii = (*new_node)->n;
	if (ascii < 0 || ascii > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line__number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ascii);
}
