#include "monty.h"

/**
 * _calloc - concats two strs
 * @num_e: number of elems
 * @sz: type
 * Return: nth
 */
void *_calloc(unsigned int num_e, unsigned int sz)
{
	void *pt = NULL;
	unsigned int idx;

	if (num_e == 0 || sz == 0)
	{
		return (NULL);
	}
	pt = malloc(num_e * sz);
	if (pt == NULL)
	{
		return (NULL);
	}
	for (idx = 0; idx < (num_e * sz); idx++)
	{
		*((char *)(pt) + idx) = 0;
	}
	return (pt);
}

/**
 * _realloc - changes size and copy content
 * @pt: pointer
 * @old: old number
 * @new_sz: new number
 * Return: nth
 */
void *_realloc(void *pt, unsigned int old, unsigned int new_sz)
{
	char *t = NULL;
	unsigned int idx;

	if (new_sz == old)
		return (pt);
	if (pt == NULL)
	{
		t = malloc(new_sz);
		if (!t)
			return (NULL);
		return (t);
	}
	if (new_sz == 0 && pt != NULL)
	{
		free(pt);
		return (NULL);
	}
	if (new_sz > old)
	{
		t = malloc(new_sz);
		if (!t)
			return (NULL);
		for (idx = 0; idx < old; idx++)
			t[idx] = *((char *)pt + idx);
		free(pt);
	}
	else
	{
		t = malloc(new_sz);
		if (!t)
			return (NULL);
		for (idx = 0; idx < new_sz; idx++)
			t[idx] = *((char *)pt + idx);
		free(pt);
	}
	return (t);
}
