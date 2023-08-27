#include "monty.h"

/**
 * rotl - Rotates the top of the stack to the bottom
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction (unused)
 *
 * This function rotates the top element of the stack to the bottom by
 * adjusting the pointers accordingly.
 */

void rotl(stack_t **stack, UN unsigned int line_number)
{
	stack_t *temp = NULL;

	/* Check if the stack is empty or has only one element */
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = (*stack);

	/* Find the last element in the stack */
	for (; temp->next; temp = temp->next)
		;

	/* Rotate the top element to the bottom */
	temp->next = *stack;
	(*stack)->prev = temp;
	temp = (*stack)->next;
	(*stack)->next = NULL;
	temp->prev = NULL;
	*stack = temp;
}
