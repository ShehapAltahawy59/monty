#include "monty.h"


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



int parse_line(char *buffer,unsigned int line_number,int format, stack_t **head)
{
    	char *opcode, *value_number;
        char *seprator= " \n\t\r";
        
        value_number = "0";
        while(isspace((unsigned char)*buffer)) buffer++;

    /* Ignore blank lines */
        if (*buffer == '\0' || buffer[0]== '#')
        {
            opcode = NULL;
        }

    /* Split the line into opcode and argument */
        else
        {
            opcode = strtok(buffer, seprator);
    
            value_number = strtok(NULL, seprator);
        }
        
        
        find_opcode(opcode,value_number,line_number,format, head);
        return (format);

}

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

