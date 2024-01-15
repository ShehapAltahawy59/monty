#include "monty.h"

void add(stack_t **head,unsigned int line__number)
{
    stack_t *pointer;
    line__number;
    int tmp;
    pointer = *head;
    
    if(pointer->prev == NULL)
    {
        printf("L%d: cant add, stack too short\n",line__number);
        
    }
    else
    {
        
        pointer = (*head)->prev;
        printf("%d\n",pointer->n);
        printf("%d\n",(*head)->n);
        tmp = (pointer->n) + (*head)->n ;
        pointer->n = tmp;
        free(*head);
        *head = pointer;
    }
}
