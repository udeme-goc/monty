#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 *
 * This function prints the character corresponding to the ASCII value at
 * the top of the stack. It handles cases where the stack is empty or the
 * value is out of range.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		if (list_opcode)
			free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	/* Check if the ASCII value is out of range */
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		if (*stack)
			free_list_stack(*stack);
		if (list_opcode)
			free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	/* Print the character corresponding to the ASCII value */
	printf("%c\n", (*stack)->n);
}
