#include "monty.h"

/**
 * _push - pushes elem to stack
 * @stack: head
 * @nline: line number
 * Return: no return
 */
void _push(stack_t **stack, unsigned int nline)
{
	int n, idx;

	if (!global.arg)
	{
		dprintf(2, "L%u: ", nline);
		dprintf(2, "usage: push integer\n");
		free_glov();
		exit(EXIT_FAILURE);
	}

	for (idx = 0; global.arg[idx] != '\0'; idx++)
	{
		if (!isdigit(global.arg[idx]) && global.arg[idx] != '-')
		{
			dprintf(2, "L%u: ", nline);
			dprintf(2, "usage: push integer\n");
			free_glov();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(global.arg);

	if (global.lifo == 1)
		add_node(stack, n);
	else
		add_node_end(stack, n);
}

/**
 * _pall - prints all values
 * @stack: head
 * @nline: line numbers
 * Return: nth
 */
void _pall(stack_t **stack, unsigned int nline)
{
	stack_t *ax;
	(void)nline;

	ax = *stack;

	while (ax)
	{
		printf("%d\n", ax->n);
		ax = ax->next;
	}
}

/**
 * _pint - prints value
 * @stack: head
 * @nline: line number
 * Return: nth
 */
void _pint(stack_t **stack, unsigned int nline)
{
	(void)nline;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: ", nline);
		dprintf(2, "can't pint, stack empty\n");
		free_glov();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes elem
 * @stack: head
 * @nline: line number
 * Return: nth
 */
void _pop(stack_t **stack, unsigned int nline)
{
	stack_t *ax;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}
	ax = *stack;
	*stack = (*stack)->next;
	free(ax);
}

/**
 * _swap - swaps top two elem
 * @stack: head
 * @nline: line number
 * Return: nth
 */
void _swap(stack_t **stack, unsigned int nline)
{
	int idx = 0;
	stack_t *ax = NULL;

	ax = *stack;

	for (; ax != NULL; ax = ax->next, idx++)
		;

	if (idx < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	ax = *stack;
	*stack = (*stack)->next;
	ax->next = (*stack)->next;
	ax->prev = *stack;
	(*stack)->next = ax;
	(*stack)->prev = NULL;
}
