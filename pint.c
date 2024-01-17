#include "monty.h"

void pint(stack_t **head,unsigned int line__number)
{
    stack_t *pointer;
    
    pointer = *head;
    
    if(pointer == NULL)
    {
        printf("L%d: can't pint, stack empty\n",line__number);
        free_nodes(head);
        exit(EXIT_FAILURE);
    }
    else
    {
        
        printf("%d\n", pointer->n);
    }
}
