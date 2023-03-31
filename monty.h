#ifndef MONTY_H
#define MONTY_H

/** libraries **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

/** structs **/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * global_var - global variables
 * @mode: 0 stack, 1 queue
 * @gbuff: getline buffer
 * @n: argument opcode
 * @head: pointer to head of stack
 * @line_number: current line number
 * @fp: pointer to file descriptor
 * Description: struct for holding global variables
 */

typedef struct global_var
{
	int mode;
	char *gbuff;
	char *n;
	stack_t *head;
	unsigned int line_number;
	FILE *fp;
} global_m;

extern global_m globm;

/** opcodes **/

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

void _add(stack_t **stack, unsigned int line_number);


/** helper functions **/

int _isdigit(char *c);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void exit_op(void);
void free_stack_t(stack_t *head);
int get_opcode(char *opcode);
int delete_node_index(stack_t **head, unsigned int index);
unsigned int len_node(stack_t **node);

#endif
