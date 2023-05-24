#include "monty.h"
/**
 * get_opc - get correct opcode
 * @oc: opcode
 * Return: pointer
 */
void (*get_opc(char *oc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instrct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int idx;

	for (idx = 0; instrct[idx].opcode; idx++)
	{
		if (_strcmp(instrct[idx].opcode, oc) == 0)
			break;
	}
	return (instrct[idx].f);
}
