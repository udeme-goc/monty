#include "monty.h"

/**
 * ptr_opcode - Returns a function pointer based on an instruction
 * @head: Head of the list of instructions
 * Return: Function pointer to an opcode implementation
 *
 * This function receives the head of the list of instructions and iterates
 * through the array of opcode structures to find a matching instruction. If
 * found, it returns corresponding function pointer. If not found, it prints
 * an error message and returns a pointer to the `nothing` function.
 */

void (*ptr_opcode(list_t *head))(stack_t **stack, unsigned int line_number)
{
	int i, n;
	char buff[10024];
	list_t *h = head;

	instruction_t arr_ptr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"queue", queue},
		{"stack", stack},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	/* Iterate through the array of opcode structures */
	for (i = 0; arr_ptr[i].f; i++)
	{
		/* Compare the instruction with the opcode */
		n = cmp_inst(head->inst, arr_ptr[i].opcode);
		if (n == 0)
		return (arr_ptr[i].f);
	}

	/* If instruction is not found, print an error message */
	for (i = 0; i < 10024; i++)
		buff[i] = 0;
	for (i = 0; h->inst[i] != '\n' && h->inst[i] && h->inst[i] != ' '; i++)
		buff[i] = h->inst[i];
	buff[i] = '\0';
	fprintf(stderr, "L%d: unknown instruction %s\n", head->n, buff);

	/* Return a pointer to the nothing function */
	return (nothing);
}
