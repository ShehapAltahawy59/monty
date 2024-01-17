#include "monty.h"

void add_to_stack(stack_t **head, unsigned int line__number)
{
    stack_t *new_node;
    (void)line__number;

    new_node = create_node(head);
    
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }

    new_node->prev = *head;
    new_node->next = NULL;
    (*head)->next = new_node;
    *head = new_node;

}
