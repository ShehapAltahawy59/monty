#include "monty.h"
stack_t *head = NULL;
/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	
	return (0);
}

/**
 * create_node - crate a new node
 * @head: pointer of pointer to head of stack
 * Return:pointer to node
*/
stack_t *create_node( int n)
{
	stack_t *new_node;
	
	new_node = malloc(sizeof(stack_t));
	
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_nodes();
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}

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




