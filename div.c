#include "monty.h"

void div_(stack_t **head,unsigned int line__number)
{
    stack_t *pointer;
    int sum;
    pointer = *head;
    
    if(pointer->prev == NULL)
    {
        free_nodes(head);
        printf("L%d: cant div, stack too short\n",line__number);
        exit(EXIT_FAILURE);
        
    }
    if ((*head)->n == 0)
    {
     printf("L%d: division by zero\n",line__number);
     free_nodes(head);
     exit(EXIT_FAILURE);
    }
    else
    {
        
        pointer = (*head)->prev;
        sum = (pointer->n) / (*head)->n;
        pointer->n = sum;
        free(*head);
        *head = pointer;
    }
}