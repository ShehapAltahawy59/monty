#include "monty.h"
/**
 * open_file - mod the top two element in stack
 * @filename: pointer to file
 * @head: pointer of pointer to head
 * Return:void
*/

void open_file(char *filename,stack_t **head )
{
	
	FILE *fn = fopen(filename,"r");
	if (filename == NULL || fn == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n",filename);
		exit(EXIT_FAILURE);
	}	
	read_file(fn,head);
	fclose(fn);

}

/**
 * read_file - mod the top two element in stack
 * @fn: pointer to file
 * @head: pointer of pointer to head
 * Return:void
*/
void read_file(FILE *fd,stack_t **head)
{
	unsigned int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format,head);
	}
	free(buffer);
}


/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, unsigned int line_number, int format,  stack_t **head)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(head);
		exit(EXIT_FAILURE);
	}
	opcode = strtok(buffer, delim);
	
	if (opcode == NULL )
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_opcode(opcode, value, line_number, format,head);
	return (format);
}
/**
 * find_opcode - perform the opcode
 * @opcode: the code
 * @value_number: the value to add in stack
 * @line_number: the number of line
 * @format:the mode atack or queue
 * @head: pointer of pointer to head
 * Return:void
*/
void find_opcode(char *opcode,char *value_number,unsigned int line__number,int format, stack_t **head)
{
	instruction_t func_list[]= {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint",pint},
		{"pop", pop},
		{"swap",swap},
		{"add",add},
		{"nop",nop},
		{"sub",sub},
		{"div",div_},
		{"mul",mul_},
		{"mod",mod_},
		{"pchar",pchar},
		{"pstr",pstr},
		{"rotl",rotl},
		{"rotr",rotr},
		{NULL, NULL}
	};
	int i,j,num,flag;

	i = 0;
	flag = 1;
	(void)format;
	
	
	while( func_list[i].opcode  )
	{
		if(opcode == NULL)
		{
			return;
		}
		if (strcmp(func_list[i].opcode,opcode) == 0)
		{
			if(strcmp(func_list[i].opcode,"push") == 0)
			{
				
				if (value_number != NULL && *value_number == '-')
				{
					
					value_number = value_number + 1;
					flag = -1;
				}
				if (value_number == NULL || value_number[0] == '\0')
				{
					
					fprintf(stderr, "L%d: usage: push integer\n",line__number);
					free_nodes(head);
					exit(EXIT_FAILURE);
				}
					
				for (j = 0; value_number[j] != '\0'; j++)
				{
					
					
					if (isdigit(value_number[i]) == 0)
					{
						
						fprintf(stderr, "L%d: usage: push integer\n",line__number);
						free_nodes(head);
						exit(EXIT_FAILURE);
					}
				}
				
				func_list[i].f(head,line__number);
				num = atoi(value_number) * flag;
				(*head)->n = num;
				
				
				
			}
			else
			{
				func_list[i].f(head,line__number);
			}
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line__number, opcode);
	free_nodes(head);
	exit(EXIT_FAILURE);
	

}

