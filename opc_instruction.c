#include "monty.h"

/**
 * _push - adds elemet to stack
 * @hd: head
 * @lnum: line number
 * Return: nth
 */
void _push(stack_t **hd, unsigned int lnum)
{
	int n, idx;

	if (!glob_v.arg)
	{
		dprintf(2, "L%u: ", lnum);
		dprintf(2, "usuage: push integer\n");
		free_glov();
		exit(EXIT_FAILURE);
	}

	for (idx = 0; glob_v.arg[idx] != '\0'; idx++)
	{
		if (!isdigit(glob_v.arg[idx]) && glob_v.arg[idx] != '-')
		{
			dprintf(2, "L%u: ", lnum);
			dprintf(2, "usuage: push integer\n");
			free_glov();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glob_v.arg);

	if (glob_v.lfo == 1)
		add_dnode(hd, n);
	else
		add_dnode_end(hd, n);
}

/**
 * _pall - prints stack val
 * @hd: head
 * @lnum: line number
 * Return: nth
 */
void _pall(stack_t **hd, unsigned int lnum)
{
	stack_t *ax;
	(void)lnum;

	ax = *hd;

	while (ax)
	{
		printf("%d\n", ax->n);
		ax = ax->next;
	}
}

/**
 * _pint - print top val of stack
 * @hd: head
 * @lnum: line number
 * Return: nth
 */
void _pint(stack_t **hd, unsigned int lnum)
{
	(void)lnum;

	if (*hd == NULL)
	{
		dprintf(2, "L%u: ", lnum);
		dprintf(2, "can't pint, stack empty\n");
		free_glov();
		exit(EXIT_FAILURE);
	}
	PRINTF("%d\n", (*hd)->n);
}

/**
 * _pop - removes top stack elem
 * @hd: head
 * @lnum: line number
 * Return: nth
 */
void _pop(stack_t **hd, unsigned int lnum)
{
	stack_t *ax;

	if (hd == NULL || *hd == NULL)
	{
		dprintf(2, "L%u: cant pop empty stack\n", lnum);
		free_glov();
		exit(EXIT_FAILURE);
	}
	ax = *hd;
	*hd = (*hd)->next;
	free(ax);
}

/**
 * _swap - swaps element
 * @hd: head
 * @lnum: line number
 * Return: nth
 */
void _swap(stack_t **hd, unsigned int lnum)
{
	int i = 0;
	stack_t *ax = NULL;

	ax = *hd;

	for (; ax != NULL; ax = ax->next, i++)
		;
	if (i < 2)
	{
		dprintf(2, "L%u: cant swap, stack too short\n", lnum);
		free_glov();
		exit(EXIT_FAILURE);
	}

	ax = *hd;
	*hd = (*hd)->next;
	ax->next = (*hd)->next;
	ax->prev = *hd;
	(*hd)->next = ax;
	(*hd)->prev = NULL;
}
