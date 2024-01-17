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

}

/**
 * read_file - mod the top two element in stack
 * @fn: pointer to file
 * @head: pointer of pointer to head
 * Return:void
*/
int read_file(FILE *fn, stack_t **head)
{
    int line_number, format;
    char *buffer;
    size_t len = 1024;

    buffer = (char *)malloc(len + 1);
    if (!buffer) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    line_number = 1;
    format = 0;

    while (fgets(buffer, len, fn)) {
        format = parse_line(buffer, line_number, format, head);
        line_number++;
    }

    free(buffer);
    return (format);
}
/**
 * trim_whitespace - remove whitespaces
 * @str: array if char
 * Return:format
*/
char *trim_whitespace(char *str)
{
    char *end;

    
    if (*str == '\0')
        return str;

    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    *(end+1) = 0;

    return str;
}

/**
 * parse_line - split the linr 
 * @buffer: array if char
 * @line_number: the number of line
 * @format:the mode atack or queue
 * @head: pointer of pointer to head
 * Return:format
*/

int parse_line(char *buffer,unsigned int line_number,int format, stack_t **head)
{
    	char *opcode, *value_number;
        char *seprator= " \n\t\r";
        
        value_number = "0";
        while(isspace((unsigned char)*buffer)) buffer++;

   
        if (*buffer == '\0' || buffer[0]== '#')
        {
            opcode = NULL;
        }

    
        else
        {
            opcode = strtok(buffer, seprator);
    
            value_number = strtok(NULL, seprator);
        }
        
        
        find_opcode(opcode,value_number,line_number,format, head);
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
    int i = 0;
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
                func_list[i].f(head,line__number);
                (*head)->n = atoi(value_number);
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
    

}

