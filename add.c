#include "monty.h"

void add(stack_t **head,unsigned int line__number)
{
    stack_t *pointer;
    int tmp;
    pointer = *head;
    
    if(pointer->prev == NULL)
    {
        printf("L%d: cant add, stack too short\n",line__number);
        
    }
    else
    {
        
        pointer = (*head)->prev;
        tmp = (pointer->n) + (*head)->n ;
        pointer->n = tmp;
        free(*head);
        *head = pointer;
    }
}
