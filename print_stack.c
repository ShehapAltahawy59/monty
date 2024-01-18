#include "monty.h"
/**
 * print_stack - print the stack
 * @new_node: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void print_stack(stack_t **new_node, unsigned int line_number)
{
	stack_t *pointer;

	(void) line_number;
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	pointer = *new_node;
	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->next;
	}
}
