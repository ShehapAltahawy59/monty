#include "monty.h"


void open_file(char *filename)
{
    FILE *fn = fopen(filename,"r"); 

    read_file(fn); 

}

int read_file(FILE *fn)
{
    int line_number,format;
    char *buffer = NULL;
    size_t *len = 0;
    
    line_number=1;
    format=0;

    for(line_number = 1; getline(&buffer, &len, fn) != -1; line_number++)
    {
        format = parse_line(buffer,line_number,format);

    }
    free(buffer);
    return (format);
}

int parse_line(char *buffer,int line_number,int format)
{
    	char *opcode, *value_number;
        char *seprator="\n";
        
        opcode = strtok(buffer, seprator);

        value_number = strtok(NULL, seprator);

        find_opcode(opcode,value_number,line_number,format);
        return (format);

}

void find_opcode(char *opcode,char *value_number,int line__number,int format)
{
    (void)line__number;
    (void)format;
    

    instruction_t func_list[]= {
		{"push", add_to_stack},
		{"pall", print_stack},
		{NULL, NULL}
	};
    int i = 0;
    while( func_list[i].opcode  )
    {
        if (strcmp(func_list[i].opcode,opcode) == 0)
        {
            func_list[i].f(&head,atoi(value_number));
        }
    }

}

