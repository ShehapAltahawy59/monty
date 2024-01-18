#include "monty.h"
/**
 * pstr - convert elemnt to string
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void pstr(stack_t **new_node, unsigned int none)
{
    
    int ascii;
	stack_t *pointer;
	
	(void)none;

	if (new_node == NULL || *new_node == NULL)
	{
		printf("\n");
		return;
	}

	pointer = *new_node;
	while (pointer != NULL)
	{
		ascii = pointer->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		pointer = pointer->next;
	}
	printf("\n");
}
	