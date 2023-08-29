#include "monty.h"

/**
 * f_stack - Changes the mode of operation to stack (LIFO).
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 *
 * Return: No return value.
 */

void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	/* Set the flag to indicate stack mode */
	bus.lifi = 0;
}
