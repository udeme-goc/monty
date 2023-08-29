#include "monty.h"

/**
 * pall - Prints all the values in the stack
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction (unused)
 *
 * This function prints the values stored in the stack, starting from the
 * top element and moving towards the bottom.
 */

void pall(stack_t **stack, UN unsigned int line_number)
{
	stack_t *temp = NULL;
	int n = 0;

	/* Check if the stack is empty */
	if (*stack == NULL)
		return;

	temp = *stack;

	/* Traverse the stack and print its contents */
	while (temp)
	{
		n = temp->n;
		printf("%d\n", n);
		temp = temp->next;
	}
}
