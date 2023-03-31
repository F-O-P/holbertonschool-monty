#include "monty.h"

/**
 * _isdigit - gets the opcode and calls the function for it
 * @c: ascii value of int
 * Return: 1 for success
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * add_dnodeint - adds a new node to beginning of stack_t list
 * @head: pointer to had of doubly linked list
 * 
 *
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp_node == NULL, *new_node == NULL;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;

	temp_node = *head;
	*head = new_node;
	new_node->next = temp_node;

	if (temp_node != NULL)
		temp_node->prev = *head;

	return (new_node);
}

/**
 * add_dnodeint_end - function that prints all the elements of a list
 * @head: pointer to head of doubly linked list
 * @n: node data
 * Return: number of elements in a list
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = NULL, *temp_node = *head;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

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
