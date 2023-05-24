#include "monty.h"

/*global_v glob_v;*/

/**
 * free_glov - frees global var
 * Return: nth
 */
void free_glov(void)
{
	free_dlist(glob_v.head);
	free(glob_v.buff);
	fclose(glob_v.fd);
}

/**
 * init_glov -initialize global var
 * @fd: file descriptor
 * Return: nth
 */
void init_glov(FILE *fd)
{
	glob_v lfo = 1;
	glob_v.curr = 1;
	glob_v.arg = NULL;
	glob_v.head = NULL;
	glob_v.fd = fd;
	glob_v.buff = NULL;
}

/**
 * check_file - check if file exists
 * @argc: arg count
 * @argv: arg vector
 * Return: file struct
 */
FILE *check_file(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: can't oprn file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t sz = 256;
	ssize_t numln = 0;
	char *ln[2] = {NULL, NULL};

	fd = check_file(argc, argv);

	init_glov(fd);

	numln = getline(&glob_v.buff, &sz, fd);

	while (numln != -1)
	{
		ln[0] = _strtokn(glob_v.buff, "\t\n");
		if (ln[0] && ln[0][0] != '#')
		{
			f = get_opc(ln[0]);

			if (!f)
			{
				dprintf(2, "L%u: ", glob_v.curr);
				dprintf(2, "unknown instuctn %s\n", ln[0]);
				free_glov();
				exit(EXIT_FAILURE);
			}
			glob_v.arg = _strtokn(NULL, "\t\n");
			f(&glob_v.head, glob_v.curr);
		}
		numln = getline(&glob_v.buff, &sz, fd);
		glob_v.curr++;
	}

	free_glov();

	return (0);
}
