#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 *
 * Return: No return value.
 */

void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;

	/* Count the number of nodes in the stack */
	while (h)
	{
		h = h->next;
		len++;
	}

	/* Check if there are at least 2 nodes in the stack */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;

	/* Swap the values of the top two elements */
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
