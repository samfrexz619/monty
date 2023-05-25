#include "monty.h"
/**
 * _strcmp - compares two strings.
 * @str1: string
 * @str2: string
 * Return: 0
 */
int _strcmp(char *str1, char *str2)
{
	int idx;

	for (idx = 0; str1[idx] == str2[idx] && str1[idx]; idx++)
		;
	if (str1[idx] > str2[idx])
		return (1);
	if (str1[idx] < str2[idx])
		return (-1);
	return (0);
}

/**
 * _srch - search
 * @str: string
 * @ch: char
 * Return: 1 or 0
 */
int _srch(char *str, char ch)
{
	int curr = 0;

	while (str[curr] != '\0')
	{
		if (str[curr] == ch)
		{
			break;
		}
		curr++;
	}
	if (str[curr] == ch)
		return (1);
	else
		return (0);
}

/**
 * _strtokn - function that cut a str
 * @str: string
 * @d: delimiters
 * Return: first partition
 */
char *_strtokn(char *str, char *d)
{
	static char *ult;
	int idx = 0, j = 0;

	if (!str)
		str = ult;
	while (str[idx] != '\0')
	{
		if (_srch(d, str[idx]) == 0 && str[idx + 1] == '\0')
		{
			ult = str + idx + 1;
			*ult = '\0';
			str = str + j;
			return (str);
		}
		else if (_srch(d, str[idx]) == 0 && _srch(d, str[idx + 1]) == 0)
			idx++;
		else if (_srch(d, str[idx]) == 0 && _srch(d, str[idx + 1]) == 1)
		{
			ult = str + idx + 1;
			*ult = '\0';
			ult++;
			str = str + j;
			return (str);
		}
		else if (_srch(d, str[idx]) == 1)
		{
			j++;
			idx++;
		}
	}
	return (NULL);
}
