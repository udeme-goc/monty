#include "monty.h"

/**
 * nothing - Frees memory and exits if there is no coincidence
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 *
 * This function typically used when there is an unexpected error or situation
 * where the interpreter needs to exit. It frees allocated memory for opcode
 * list and the stack, then exits the program with a failure status.
 */

void nothing(stack_t **stack, UN unsigned int line_number)
{
	/* Free opcode list if it exists */
	if (list_opcode)
		free_list_opcode(list_opcode);

	/* Free stack if it exists */
	if (*stack)
		free_list_stack(*stack);

	/* Exit program with failure status */
	exit(EXIT_FAILURE);
}
