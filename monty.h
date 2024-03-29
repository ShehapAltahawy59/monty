#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
void open_file(char *filename,stack_t *head);
void read_file(FILE *fd);
int parse_line(char *buffer,unsigned int line_number,int format);
void find_opcode(char *opcode,char *value_number,unsigned int line__number,int format);
void add_to_stack(stack_t **head,unsigned int line__number);
stack_t *create_node( int n);
void print_stack(stack_t **head, unsigned int none);
void pint(stack_t **head,unsigned int line__number);
void pop(stack_t **head,unsigned int line__number);
void swap(stack_t **head,unsigned int line__number);
void add(stack_t **head,unsigned int line__number);
void nop(stack_t **head,unsigned int line__number);
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void free_nodes();
void sub(stack_t **head,unsigned int line__number);
void div_(stack_t **head,unsigned int line__number);
void mul_(stack_t **head,unsigned int line__number);
void mod_(stack_t **head,unsigned int line__number);
void pchar(stack_t **head,unsigned int line__number);
void pstr(stack_t **head, unsigned int none);
void rotl(stack_t **head, unsigned int none);
void rotr(stack_t **head, unsigned int none);
void call_fun(instruction_t func, char *opcode, char *value_number, unsigned int line__number, int format);
 void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);
 #endif

