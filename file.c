#include "monty.h"
/**
 * open_file - mod the top two element in stack
 * @filename: pointer to file
 * @head: pointer of pointer to head
 * Return:void
*/

void open_file(char *filename ,stack_t *head)
{
	
	FILE *fn = fopen(filename,"r");
	(void)head;
	if (filename == NULL || fn == NULL)
	{
		err(2, filename);
	}	
	read_file(fn);
	fclose(fn);

}

/**
 * read_file - mod the top two element in stack
 * @fn: pointer to file
 * @head: pointer of pointer to head
 * Return:void
*/
void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
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

int parse_line(char *buffer, unsigned int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		err(4);
	}
	opcode = strtok(buffer, delim);
	
	if (opcode == NULL )
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_opcode(opcode, value, line_number, format);
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
void find_opcode(char *opcode,char *value_number,unsigned int line__number,int format)
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
	int i,flag;

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i], opcode, value_number, line__number, format);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		err(3, line__number, opcode);
	}
		

}

/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(instruction_t func, char *opcode, char *value_number, unsigned int line__number, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value_number != NULL && value_number[0] == '-')
		{
			value_number = value_number + 1;
			flag = -1;
		}
		if (value_number == NULL)
		{
			err(5, line__number);
		}
		for (i = 0; value_number[i] != '\0'; i++)
		{
			if (isdigit(value_number[i]) == 0)
				{
						
					err(5, line__number);
				}
		}
		node = create_node(atoi(value_number) * flag);
		if (format == 0)
			func.f(&node, line__number);
	}
	else
		func.f(&head, line__number);
}

