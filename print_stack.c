#include "monty.h"
/**
 * print_stack - print the stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void print_stack(stack_t **head, unsigned int none)
{
	stack_t *pointer;
	(void)none;

	pointer = *head;

	if (pointer == NULL)
	{
		return;
	}
	while(pointer)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->prev;
	}
}
