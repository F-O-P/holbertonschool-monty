#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: pointer to pointer to the stack
 * @line_number: current line number
 * Return: Always 0
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int i;

	if (!_isdigit(globm.n))
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	i = atoi(globm.n);
	if (globm.mode == 0)
		add_dnodeint(stack, i);
	else
		add_dnodeint_end(stack, i);
}

/**
 * _pall - prints all values on the stack, starting from the top
 * @stack: pointer to pointer to the stack
 * @line_number: current line number
 * Return: Always 0
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (stack && tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to pointer to the stack
 * @line_number: current line number
 * Return: Always 0
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: pointer to pointer to the stack
 * @line_number: current line number
 * Return: Always 0
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}
	delete_node_index(stack, 0);
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to poiter to the stack
 * @line_number: current line number
 * Return: Always 0
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *temp2, *temp3;
	int count = 0;

	while (temp)
		temp = temp->next, count++;
	if (count < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}
	temp = temp3 = *stack;
	temp2 = temp->next;
	temp->next = temp2->next, temp->prev = temp2;
	temp2->next = temp3, temp2->prev = temp3->prev;
	*stack = temp2;
}
