#include "monty.h"

/**
 * pop - Removes the top element from the stack
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 *
 * This function removes the top element from the stack. It handles cases
 * where the stack is empty or has only one element.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len(*stack);

	/* Check if the stack is empty */
	if (n <= 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		if (list_opcode != NULL)
			free_list_opcode(list_opcode);
		if (*stack != NULL)
			free_list_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/* Handle case when the stack has only one element */
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}

	/* Remove the top element and adjust the pointers */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
	temp = NULL;
}

