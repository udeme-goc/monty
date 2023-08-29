#include "monty.h"

/**
 * f_pchar - Prints the character at the top of the stack,
 * followed by a new line.
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 *
 * Return: No return value.
 */

void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;

	/* Check if the stack is empty */
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Check if the value is within the valid character range */
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Print the character at the top of the stack */
	printf("%c\n", h->n);
}
