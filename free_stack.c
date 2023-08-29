#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Pointer to the head of the stack.
 */

void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;

	/* Traverse the linked list and free each node */
	while (head)
	{
		aux = head->next;
		free(head); /* Free the current node */
		head = aux; /* Move to the next node */
	}
}
