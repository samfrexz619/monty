#include "monty.h"

global_v global;

/**
 * free_glov - frees the global variables
 *
 * Return: no return
 */
void free_glov(void)
{
	free_list(global.head);
	free(global.buff);
	fclose(global.fd);
}

/**
 * init_glov - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void init_glov(FILE *fd)
{
	global.lifo = 1;
	global.curr = 1;
	global.arg = NULL;
	global.head = NULL;
	global.fd = fd;
	global.buff = NULL;
}

/**
 * check_file - checks if the file exists
 * @argc: argument count
 * @argv: argument vector
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
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
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
	char *lines[2] = {NULL, NULL};

	fd = check_file(argc, argv);
	init_glov(fd);
	numln = getline(&global.buff, &sz, fd);
	while (numln != -1)
	{
		lines[0] = _strtokn(global.buff, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opc(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", global.curr);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_glov();
				exit(EXIT_FAILURE);
			}
			global.arg = _strtokn(NULL, " \t\n");
			f(&global.head, global.curr);
		}
		numln = getline(&global.buff, &sz, fd);
		global.curr++;
	}

	free_glov();

	return (0);
}
