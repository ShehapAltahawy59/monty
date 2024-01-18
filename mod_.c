#include "monty.h"
/**
 * mod_ - mod the top two element in stack
 * @new_node: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void mod_(stack_t **new_node,unsigned int line__number)
{
    
	int result;

	if (new_node == NULL || *new_node == NULL || (*new_node)->next == NULL)
    {
		more_err(8, line__number, "mod");
		
	}


	if ((*new_node)->n == 0)
	{
	 more_err(9, line__number);
	}
	(*new_node) = (*new_node)->next;
	result = (*new_node)->n % (*new_node)->prev->n;
	(*new_node)->n = result;
	free((*new_node)->prev);
	(*new_node)->prev = NULL;
}
