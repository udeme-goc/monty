#include "monty.h"

/**
 * stack_len - Calculates the length of the stack
 * @head: Pointer to the head of the stack
 * Return: Length of the stack
 *
 * This function calculates and returns the number of elements in the stack.
 */

int stack_len(stack_t *head)
{
	int i = 0;

	/* Traverse the stack while counting elements */
	for (; head; head = head->next, i++)
		;

	return (i);  /* Return the calculated length */
}

