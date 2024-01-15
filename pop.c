#include "monty.h"

void pop(stack_t **head,unsigned int line__number)
{
    stack_t *pointer;
    (void)line__number;

    if (*head == NULL)
    {
        printf("L%d: can't pop an empty stack\n", line__number);
        return;
    }
    
    pointer = *head;
    printf("%d\n", (*head)->n);
    (*head) = (*head)->prev;
    free(pointer);
    
}
