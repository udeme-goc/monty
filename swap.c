#include "monty.h"

/**
 * swap - Swaps the top two values in the stack
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 *
 * This function swaps the positions of the top two elements in the stack.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len(*stack);

	/* Check if the stack has at least 2 elements */
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		if (list_opcode != NULL)
			free_list_opcode(list_opcode);
		if (*stack != NULL)
			free_list_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if (n == 2)
	{
		/* Swap top two elements when there are only two elements in the stack */
		temp = (*stack)->next;
		(*stack)->next = NULL;
		(*stack)->prev = temp;
		temp->prev = NULL;
		temp->next = *stack;
		*stack = temp;
	}
	else
	{
		/* Swap top two elements when there are more than two elements in stack */
		temp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		(*stack)->prev = temp;
		temp->next->prev = *stack;
		temp->prev = NULL;
		temp->next = *stack;
		*stack = temp;
	}
}
