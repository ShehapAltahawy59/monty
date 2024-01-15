#include "monty.h"

void swap(stack_t **head,unsigned int line__number)
{
    stack_t *pointer;
    int tmp;
    pointer = *head;
    
    if(pointer->prev == NULL)
    {
        printf("L%d: cant swap, stack too short\n",line__number);
        
    }
    else
    {
        pointer = (*head)->prev;
        tmp = pointer->n;
        pointer->n = (*head)->n;
        (*head)->n = tmp;
    }
}
