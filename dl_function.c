#include "monty.h"

/**
 *add_node_end - add  node
 *@stack: head
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_node_end(stack_t **stack, const int n)
{
	stack_t *tmp, *ax;

	if (stack == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glov();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*stack == NULL)
	{
		tmp->next = *stack;
		tmp->prev = NULL;
		*stack = tmp;
		return (*stack);
	}
	ax = *stack;
	while (ax->next)
		ax = ax->next;
	tmp->next = ax->next;
	tmp->prev = ax;
	ax->next = tmp;
	return (ax->next);
}

/**
 *add_node - add a node at the begining
 *@stack: head
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *tmp;

	if (stack == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glov();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*stack == NULL)
	{
		tmp->next = *stack;
		tmp->prev = NULL;
		*stack = tmp;
		return (*stack);
	}
	(*stack)->prev = tmp;
	tmp->next = (*stack);
	tmp->prev = NULL;
	*stack = tmp;
	return (*stack);
}

/**
 * free_list - frees linked list
 *
 * @stack: head
 * Return: no return
 */
void free_list(stack_t *stack)
{
	stack_t *tmp;

	while ((tmp = stack) != NULL)
	{
		stack = stack->next;
		free(tmp);
	}
}
