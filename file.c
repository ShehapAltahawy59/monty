#include "monty.h"


void open_file(char *filename,stack_t **head )
{
    FILE *fn = fopen(filename,"r"); 
    printf("open_file\n");
    read_file(fn,head); 

}

int read_file(FILE *fn, stack_t **head)
{
    int line_number,format;
    char *buffer = NULL;
    size_t len = 0;
    
    line_number=1;
    format=0;

    for(line_number = 1; getline(&buffer, &len, fn) != -1; line_number++)
    {
        printf("read_file\n");
        format = parse_line(buffer,line_number,format,head);

    }
    free(buffer);
    return (format);
}

int parse_line(char *buffer,int line_number,int format, stack_t **head)
{
    	char *opcode, *value_number;
        char *seprator=" \n\t";
        
        opcode = strtok(buffer, seprator);

        value_number = strtok(NULL, seprator);
        printf("parse_line\n");
        find_opcode(opcode,value_number,line_number,format, head);
        return (format);

}

void find_opcode(char *opcode,char *value_number,int line__number,int format, stack_t **head)
{
    instruction_t func_list[]= {
		{"push", add_to_stack},
		{"pall", print_stack},
		{NULL, NULL}
	};
    int i = 0;
    (void)line__number;
    (void)format;
    
    printf("%s\n",opcode);
    printf("%s\n",value_number);
    while( func_list[i].opcode  )
    {
        if (strcmp(func_list[i].opcode,opcode) == 0)
        {
            printf("%s\n",func_list[i].opcode);
            func_list[i].f(head,atoi(value_number));
            return;
        }
        i++;
    }
    return;

}

