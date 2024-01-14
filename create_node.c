#include "monty.h"

stack_t *create_node(int value)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->n = value;
    return (new_node);
}
