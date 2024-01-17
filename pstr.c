#include "monty.h"
/**
 * pstr - convert elemnt to string
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void pstr(stack_t **head, unsigned int none)
{
	stack_t *pointer;
	char *str;
	int num,index;
	(void)none;
	
	str = malloc(sizeof(char) * 1024);
	pointer = *head;
	index=0;
	if (pointer == NULL)
	{
		fprintf(stdout,"\n");
		return;
	}
	while(pointer)
	{
		num = pointer->n;
		if (num == 0 || (num < 65 && num > 90) || (num < 97 && num > 122))
		{
			fprintf(stdout,"%s",str);
			fprintf(stdout,"\n");
			free(str);
			return;
		}
		str[index] = (char)num;
		index++;
		pointer = pointer->prev;
	}
}
