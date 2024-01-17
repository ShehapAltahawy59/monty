#include "monty.h"
/**
 * create_node - crate a new node
 * @head: pointer of pointer to head of stack
 * Return:pointer to node
*/
stack_t *create_node(stack_t **head)
{
	stack_t *new_node;
	
	new_node = malloc(sizeof(stack_t));
	
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_nodes(head);
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
