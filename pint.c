#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 *
 * This function prints the integer value at the top of the stack. It handles
 * the case where the stack is empty.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_list_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/* Print the integer value at the top of the stack */
	printf("%d\n", (*stack)->n);
}
