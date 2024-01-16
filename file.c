#include "monty.h"


void open_file(char *filename,stack_t **head )
{
    FILE *fn = fopen(filename,"r");
    if (filename == NULL || fn == NULL)
		err(2, filename);
    read_file(fn,head);

}

int read_file(FILE *fn, stack_t **head)
{
    int line_number, format;
    char *buffer;
    size_t len = 1024;

    buffer = (char *)malloc(len + 1);
    if (!buffer) {
        printf("Error: Can't open file <file>");
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

    
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    
    *(end+1) = 0;

    return str;
}

int parse_line(char *buffer,unsigned int line_number,int format, stack_t **head)
{
    	char *opcode, *value_number;
        char *seprator=" \n\t";
        
        if (buffer == NULL)
		    err(4);
        opcode = strtok(buffer, seprator);
        opcode = trim_whitespace(opcode);

        value_number = strtok(NULL, seprator);
        
        find_opcode(opcode,value_number,line_number,format, head);
        return (format);

}

void find_opcode(char *opcode,char *value_number,unsigned int line__number,int format, stack_t **head)
{
    instruction_t func_list[]= {
		{"push", add_to_stack},
		{"pall", print_stack},
        {"pop", pop},
        {"swap",swap},
        {"add",add},
        {"nop",nop},
		{NULL, NULL}
	};
    int i = 0;
    (void)value_number;
    (void)format;
    
    
    while( func_list[i].opcode  )
    {
        if (strcmp(func_list[i].opcode,opcode) == 0)
        {
            
            
            
            func_list[i].f(head,line__number);
            return;
        }
        i++;
    }
    return;

}

