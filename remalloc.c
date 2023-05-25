#include "monty.h"
/**
 * _calloc - concatenate str
 * @num: number of elem
 * @sz: type of elements
 * Return: nth
 */
void *_calloc(unsigned int num, unsigned int sz)
{
	void *ptr = NULL;
	unsigned int idx;

	if (num == 0 || sz == 0)
	{
		return (NULL);
	}
	ptr = malloc(num * sz);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (idx = 0; idx < (num * sz); idx++)
	{
		*((char *)(ptr) + idx) = 0;
	}
	return (ptr);
}
/**
 * _realloc - change size
 * @ptr: pointer
 * @old: old num
 * @new: new num
 * Return: nth
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	char *p = NULL;
	unsigned int idx;

	if (new == old)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new > old)
	{
		p = malloc(new);
		if (!p)
			return (NULL);
		for (idx = 0; idx < old; idx++)
			p[idx] = *((char *)ptr + idx);
		free(ptr);
	}
	else
	{
		p = malloc(new);
		if (!p)
			return (NULL);
		for (idx = 0; idx < new; idx++)
			p[idx] = *((char *)ptr + idx);
		free(ptr);
	}
	return (p);
}
