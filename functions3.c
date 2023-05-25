#include "monty.h"

/**
 * _div - divides func
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _div(stack_t **stack, unsigned int nline)
{
	int idx = 0;
	stack_t *ax = NULL;

	ax = *stack;

	for (; ax != NULL; ax = ax->next, idx++)
		;

	if (idx < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	ax = (*stack)->next;
	ax->n /= (*stack)->n;
	_pop(stack, nline);
}

/**
 * _mul - multiplies elelm
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _mul(stack_t **stack, unsigned int nline)
{
	int idx = 0;
	stack_t *ax = NULL;

	ax = *stack;

	for (; ax != NULL; ax = ax->next, idx++)
		;

	if (idx < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	ax = (*stack)->next;
	ax->n *= (*stack)->n;
	_pop(stack, nline);
}

/**
 * _mod - computes remainder
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _mod(stack_t **stack, unsigned int nline)
{
	int idx = 0;
	stack_t *ax = NULL;

	ax = *stack;

	for (; ax != NULL; ax = ax->next, idx++)
		;

	if (idx < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	ax = (*stack)->next;
	ax->n %= (*stack)->n;
	_pop(stack, nline);
}
/**
 * _pchar - print char
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _pchar(stack_t **stack, unsigned int nline)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", nline);
		free_glov();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - prints str
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _pstr(stack_t **stack, unsigned int nline)
{
	stack_t *ax;
	(void)nline;

	ax = *stack;

	while (ax && ax->n > 0 && ax->n < 128)
	{
		printf("%c", ax->n);
		ax = ax->next;
	}

	printf("\n");
}
