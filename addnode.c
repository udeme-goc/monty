#include "monty.h"

/**
 * addnode - Adds a new node to the head of the stack.
 * @head: Pointer to the head of the stack.
 * @n: Value for the new node.
 *
 * Return: No return value.
 */

void addnode(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Update previous pointer of the current head */
	if (aux != NULL)
		aux->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
