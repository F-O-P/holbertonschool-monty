#include "monty.h"

/**
 * _isdigit - gets the opcode and calls the function for it
 * @c: ascii value of int
 * Return: 1 for success
 */

int _isdigit(char *c)
{
	if (!c)
		return (0);
	if (*c == '-')
		c++;
	for (; *c; c++)
		if (!isdigit(*c))
			return (0);
	return (1);
}

/**
 * add_dnodeint - adds a new node to beginning of stack_t list
 * @head: pointer to had of doubly linked list
 * @n: node data
 * Return: number of elements in a list
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit_op();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * add_dnodeint_end - function that prints all the elements of a list
 * @head: pointer to head of doubly linked list
 * @n: node data
 * Return: number of elements in a list
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp_node = *head;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit_op();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	if (!(*head))
	{
		new_node->prev = NULL, new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (temp_node->next)
		temp_node = temp_node->next;

	new_node->prev = temp_node;
	new_node->next = NULL;
	temp_node->next = new_node;

	return (new_node);
}

/**
 * exit_op - free and close operations
 * Return: Always 0
 */

void exit_op(void)
{
	free(globm.gbuff), fclose(globm.fp);
	free_stack_t(globm.head);
}

/**
 * free_stack_t - free the memory on stack
 * @head: pointer to head
 * Return: Always 0
 */

void free_stack_t(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
