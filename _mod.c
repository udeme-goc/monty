#include "monty.h"

/**
 * _mod - Computes modulus of 2nd element by top element of stack
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	/* Get the number of elements in the stack */
	n = stack_len(*stack);

	/* Check if there are at least two elements to perform modulus */
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);

		/* Clean up and exit */
		free_opcode_and_stack();
	}

	/* Check for division by zero */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);

		/* Clean up and exit */
		free_opcode_and_stack();
	}

	/* Perform modulus and update the stack */
	temp = *stack;
	temp->next->n %= temp->n;
	pop(stack, line_number);
}
