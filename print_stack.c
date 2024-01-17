#include "monty.h"

void print_stack(stack_t **head, unsigned int none)
{
    stack_t *pointer;
    (void)none;

    pointer = *head;

    if (pointer == NULL)
    {
        return;
    }
    while(pointer)
    {
        printf("%d\n", pointer->n);
        pointer = pointer->prev;
    }
}
