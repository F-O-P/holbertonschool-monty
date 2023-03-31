#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to pointer to the stack
 * @line_number: current line number
 * Return: Always 0
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int count = 0, tmpn;

	while (temp)
		temp = temp->next, count++;
	if (count < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	tmpn = (*stack)->n;
	delete_node_index(stack, 0);
	(*stack)->n += tmpn;
}

/**
 * _nop - doesn’t do anything
 * @stack: pointer to pointer to the stack
 * @line_number: current line number
 * Return: Always 0
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
