#include "monty.h"

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
		free_nodes(&head);
		exit(EXIT_FAILURE);
	}
	open_file(argv[1],&head);
	free_nodes(&head);
	
	return (0);
}

