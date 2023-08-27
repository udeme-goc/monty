#include "monty.h"

/**
 * _div - Divides the second element by the top element of the stack
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	/* Get the number of elements in the stack */
	n = stack_len(*stack);

	/* Check if there are at least two elements to perform division */
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);

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

	/* Perform division and update the stack */
	temp = *stack;
	temp->next->n /= temp->n;
	pop(stack, line_number);
}
