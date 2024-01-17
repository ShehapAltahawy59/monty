#include "monty.h"

void free_nodes(stack_t **head)
{
	stack_t *tmp;

	if (*head == NULL)
		return;

	while (*head != NULL)
	{
		tmp = *head;
		(*head) = (*head)->next;
		free(tmp);
	}
}
