#include "monty.h"

/**
 * sub - Subtracts the top value from the second top value
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 *
 * This function subtracts the value of the top element from the value of the
 * second top element in the stack. It then removes the top element.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len(*stack);

	/* Check if the stack has at least 2 elements */
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		if (list_opcode != NULL)
			free_list_opcode(list_opcode);
		if (*stack != NULL)
			free_list_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	/* Subtract the value of the top element from the second top element */
	temp->next->n -= temp->n;

	/* Remove the top element */
	pop(stack, line_number);
}
