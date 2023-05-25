#include "monty.h"

/**
 * _rotl - rotates elem
 * @stack: head
 * @nline: line number;
 * Return: nth
 */
void _rotl(stack_t **stack, unsigned int nline)
{
	stack_t *ax1 = NULL;
	stack_t *ax2 = NULL;
	(void)nline;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	ax1 = (*stack)->next;
	ax2 = *stack;

	for (; ax2->next != NULL; ax2 = ax2->next)
		;

	ax1->prev = NULL;
	ax2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = ax2;
	*stack = ax1;
}

/**
 * _rotr - reverse the stack
 * @stack: head
 * @nline: line number
 * Return: nth
 */
void _rotr(stack_t **stack, unsigned int nline)
{
	stack_t *ax = NULL;
	(void)nline;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	ax = *stack;

	for (; ax->next != NULL; ax = ax->next)
		;

	ax->prev->next = NULL;
	ax->next = *stack;
	ax->prev = NULL;
	(*stack)->prev = ax;
	*stack = ax;
}
