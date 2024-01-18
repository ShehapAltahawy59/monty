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
		string_err(11, line__number);
	}

	ascii = (*new_node)->n;
	if (ascii < 0 || ascii > 127)
	{
		string_err(10, line__number);
	}
	printf("%c\n", ascii);
}
