#include "monty.h"

void add_to_stack(stack_t **head,int value)
{
    stack_t *new_node;

    new_node = create_node(value);

    if(head == NULL)
    {
        head = new_node;
        return;
    }

    new_node->prev = head;
    new_node->next = NULL;
    (*head)->next = new_node;
    *head = new_node;

}
