#include "monty.h"

void pchar(stack_t **head,unsigned int line__number)
{
    stack_t *pointer;
    int num;
    pointer = *head;
    
    if(pointer == NULL)
    {
        printf("L%d: can't pchar, stack empty\n",line__number);
        free_nodes(head);
        exit(EXIT_FAILURE);
    }
    else
    {
        num = pointer->n;
        if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122))
        {
            char ch = (char) num;
            printf("%c\n",ch);
        }
        else
        {
            printf("L%d: can't pchar, value out of range\n", line__number);
        }
    }
}
