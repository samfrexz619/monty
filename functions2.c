#include "monty.h"

/**
 * _queue - sets the format
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _queue(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;

	global.lifo = 0;
}

/**
 * _stack - sets the format of LIFO
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _stack(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;

	global.lifo = 1;
}

/**
 * _add - adds the top two elem
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _add(stack_t **stack, unsigned int nline)
{
	int idx = 0;
	stack_t *ax = NULL;

	ax = *stack;

	for (; ax != NULL; ax = ax->next, idx++)
		;

	if (idx < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	ax = (*stack)->next;
	ax->n += (*stack)->n;
	_pop(stack, nline);
}

/**
 * _nop - doesn't do anythinhg
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}

/**
 * _sub - subtracts the top elems
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _sub(stack_t **stack, unsigned int nline)
{
	int idx = 0;
	stack_t *ax = NULL;

	ax = *stack;

	for (; ax != NULL; ax = ax->next, idx++)
		;

	if (idx < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	ax = (*stack)->next;
	ax->n -= (*stack)->n;
	_pop(stack, nline);
}
