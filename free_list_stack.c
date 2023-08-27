#include "monty.h"

/**
 * free_list_stack - Frees the memory of a stack linked list
 * @head: Pointer to the head of the stack
 *
 * This function traverses the linked list and frees the memory of each node,
 * including the node itself.
 */

void free_list_stack(stack_t *head)
{
	stack_t *temp;

	/* Traverse the linked list */
	while (head)
	{
		/* Store the current node in a temporary variable */
		temp = head;

		/* Move to the next node */
		head = head->next;

		/* Free the memory of the current node */
		free(temp);
	}
}
