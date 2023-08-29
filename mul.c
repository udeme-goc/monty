#include "monty.h"

/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 *
 * Return: No return value.
 */

void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;

	/* Calculate the length of the stack */
	while (h)
	{
		h = h->next;
		len++;
	}

	/* Check if there are at least 2 elements in the stack */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;

	/* Perform the multiplication */
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
