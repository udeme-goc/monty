#include "monty.h"

/**
 * free_list_opcode - Frees a linked list of opcode structures
 * @head: Pointer to the head of the linked list
 *
 * This function traverses the linked list and frees each node, including the
 * memory allocated for the 'inst' string and the node itself.
 */

void free_list_opcode(list_t *head)
{
	list_t *temp;

	/* Traverse the linked list */
	while (head)
	{
		/* Store the current node in a temporary variable */
		temp = head;

		/* Move to the next node */
		head = head->next;

		/* Free the memory allocated for the 'inst' string */
		free(temp->inst);

		/* Free the memory of the current node */
		free(temp);
	}
}
