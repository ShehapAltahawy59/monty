#include "monty.h"
/**
 * swap - swap the top two element in stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void swap(stack_t **head,unsigned int line__number)
{
    stack_t *pointer;
    int tmp;
    pointer = *head;
    
    if(pointer->prev == NULL)
    {
        printf("L%d: cant swap, stack too short\n",line__number);
        free_nodes(head);
        exit(EXIT_FAILURE);
    }
    else
    {
        pointer = (*head)->prev;
        tmp = pointer->n;
        pointer->n = (*head)->n;
        (*head)->n = tmp;
    }
}
