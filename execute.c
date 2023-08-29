#include "monty.h"

/**
 * execute - Executes the opcode.
 * @content: Line content.
 * @stack: Pointer to the head of the linked list - stack.
 * @counter: Line counter.
 * @file: Pointer to the Monty file.
 *
 * Return: 0 on success, 1 if opcode not found.
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
		{"nop", f_nop}, {"sub", f_sub}, {"div", f_div},
		{"mul", f_mul}, {"mod", f_mod}, {"pchar", f_pchar},
		{"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr},
		{"queue", f_queue}, {"stack", f_stack}, {NULL, NULL}
	};

	unsigned int i = 0;
	char *op;

	/* Tokenize the opcode */
	op = strtok(content, " \n\t");

	/* Ignore comments */
	if (op && op[0] == '#')
		return (0);

	/* Tokenize the argument */
	bus.arg = strtok(NULL, " \n\t");

	/* Iterate through the opcode function array */
	while (opst[i].opcode && op)
	{
		/* Compare the opcode with the current element in the array */
		if (strcmp(op, opst[i].opcode) == 0)
		{
			/* Call the corresponding opcode function */
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	/* Handle unknown opcode */
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
