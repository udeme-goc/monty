#include "monty.h"

/**
 * rotr - Rotates the bottom element of the stack to the top
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction (unused)
 *
 * This function rotates the bottom element of the stack to the top by
 * adjusting the pointers accordingly.
 */

void rotr(stack_t **stack, UN unsigned int line_number)
{
	stack_t *temp = NULL;

	/* Check if the stack is empty or has only one element */
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = (*stack);

	/* Find the last element in the stack */
	for (; temp->next; temp = temp->next)
		;

	/* Adjust the pointers to rotate the bottom element to the top */
	temp->prev->next = NULL;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}
