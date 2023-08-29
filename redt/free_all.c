#include "monty.h"

/**
 * free_all - Frees all the allocated memory for instructions and stack
 * @list: Pointer to the list of instructions
 * @stack: Pointer to the stack
 */

void free_all(list_t *list, stack_t *stack)
{
	/* Free the list of instructions */
	if (list_opcode)
		free_list_opcode(list);

	/* Free the stack */
	if (stack)
	free_list_stack(stack);
}

