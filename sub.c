#include "monty.h"

void sub(stack_t **head,unsigned int line__number)
{
    stack_t *pointer;
    int sum;
    pointer = *head;
    
    if(pointer->prev == NULL)
    {
        printf("L%d: cant sub, stack too short\n",line__number);
        free_nodes(head);
        exit(EXIT_FAILURE);
    }
    else
    {
        
        pointer = (*head)->prev;
        sum = (*head)->n - (pointer->n) ;
        pointer->n = sum;
        free(*head);
        *head = pointer;
    }
}
