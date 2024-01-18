#include "monty.h"
/**
 * free_nodes - print the head of stack
 * @head: pointer of pointer to head of stack
 * Return:void
*/
void free_nodes()
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
