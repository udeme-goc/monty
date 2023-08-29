#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 * @head: Pointer to the stack's head.
 * @counter: Line number (unused).
 *
 * Return: No return value.
 */

void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;

	/* If the stack is empty or has only one element, no rotation needed */
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	/* Traverse to the end of the stack */
	while (copy->next)
	{
		copy = copy->next;
	}

	/* Rotate the stack to the bottom */
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
