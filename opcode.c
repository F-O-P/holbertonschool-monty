#include "monty.h"

/**
 * get_opcode - gets the opcode and calls the function for it
 * @opcode: string of opcodes
 * Return: 0 for success and exit if failure
 */

int get_opcode(char *opcode)
{
	int i;
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap" _swap},
		{"add", _add},
		{"nop", _nop},
	};

	for (i = 0; ops[i].opcode && opcode; i++)
		if (!strcmp(opcode, ops[i].opcode))
		{
			ops[i].f(&(globm.head), globm.line_number;
			return (0);
		}

	dprintf(2, "L%d: unknown instruction %s\n", globm.line_number, opcode);
	exit(EXIT_FALIURE);
}
