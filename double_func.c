#include "monty.h"

/**
 * add_dnode_end - add node to the end of the list
 * @head: head
 * @data: data
 * Return: doubly list
 */
stack_t *add_dnode_end(stact_t **head, const int data)
{
	stack_t *tmp, *ax;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	tmp->data = data;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	ax = *head;
	while (ax->next)
		ax = ax->next;
	tmp->next = ax->next;
	tmp->prev = ax;
	ax->next = tmp;
	return (ax->next);
}

/**
 * add_dnode - add node at the beginning
 * @head: head
 * @data: data
 * Return: doubly list
 */
stack_t *add_dnode(stack_t **head, const int data)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	tmp->data = data;
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 * free_dlist - frees the linked list
 * @head: head
 * Return: nth
 */
void free_dlist(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
