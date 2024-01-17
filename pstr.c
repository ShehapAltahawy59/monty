#include "monty.h"

void pstr(stack_t **head, unsigned int none)
{
    stack_t *pointer;
    char *str;
    int num,index;
    (void)none;
    
    str = malloc(sizeof(char) * 1024);
    pointer = *head;
    index=0;
    if (pointer == NULL)
    {
        printf("\n");
        return;
    }
    while(pointer)
    {
        num = pointer->n;
        if (num == 0 || (num < 65 && num > 90) || (num < 97 && num > 122))
        {
            printf("%s",str);
            printf("\n");
            return;
        }
        str[index] = (char)num;
        index++;
        pointer = pointer->prev;
    }
}
