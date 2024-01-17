#include "monty.h"
/**
 * rotl - rotl to stack
 * @head: pointer of pointer to head of stack
 * @line_number: the line which is excuted
 * Return:void
*/
void rotl(stack_t **head, unsigned int none)
{
    stack_t *last,*first,*new_node;
    (void)none;

    last = *head;
    first = *head;
    


    if (last == NULL)
    {
        return;
    }
    while(last->prev)
    {
        
        last = last->prev;
    }

    new_node = create_node(head);
    new_node->n = first->n;
    new_node->next = last;
    new_node->prev = NULL;
    last->prev = new_node;
    
    *head = (first->prev);
    free(first);
    
    
}
