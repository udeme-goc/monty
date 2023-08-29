#include "monty.h"

/**
 * f_pop - Removes the top element from the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 *
 * Return: No return value.
 */

void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	/* Check if the stack is empty */
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;

	/* Remove the top element from the stack */
	*head = h->next;
	free(h);
}
