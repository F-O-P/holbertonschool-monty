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

void _pall(stact_t **stack, unsigned int line_number)
{
	//add variables used here//


	//if the stack is empty, don't print anything//

	if (*stack == NULL)
		return;

	//print all values on the stack, starting from the top//

		
}
