#include "monty.h"

/**
 * _strcmp - function to compare
 * @str: string
 * @str2: string
 * Return: 0 if str are equal
 */
int _strcmp(char *str, char *str2)
{
	int idx;

	for (idx = 0; str[idx] == str2[idx] && str[idx]; idx++)
		;

	if (str[idx] > str2[idx])
		return (1);
	if (str[idx] < str2[idx])
		return (-1);
	return (0);
}

/**
 * _srch - search func
 * @str: string
 * @ch: char
 * Return: 1 or 0
 */
int _srch(char *str, char ch)
{
	int cur = 0;

	while (str[cur] != '\0')
	{
		if (str[cur] == ch)
		{
			break;
		}
		cur++;
	}
	if (str[cur] == ch)
		return (1);
	else
		return (0);
}

/**
 * _strtokn - function to cut str into tokens
 * @str: string
 * @d: delimiters
 * Return: partition
 */
char *_strtokn(char *str, char *d)
{
	static char *ult;
	int idx = 0, k = 0;

	if (!str)
		str = ult;
	while (str[idx] != '\0')
	{
		if (_srch(d, str[idx]) == 0 && str[idx + 1] == '\0')
		{
			ult = str + idx + 1;
			*ult = '\0';
			str = str + k;
			return (str);
		}
		else if (_srch(d, str[idx]) == 0 && _srch(d, str[idx + 1]) == 0)
			idx++;
		else if (_srch(d, str[idx]) == 0 && _srch(d, str[idx + 1]) == 1)
		{
			ult = str + idx + 1;
			*ult = '\0';
			ult++;
			str = str + k;
			return (str);
		}
		else if (_srch(d, str[idx]) == 1)
		{
			k++;
			idx++;
		}
	}
	return (NULL);
}
