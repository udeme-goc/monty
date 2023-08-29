#include "monty.h"

/**
 * f_queue - Changes the mode of operation to queue (FIFO).
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 *
 * Return: No return value.
 */

void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	/* Set the flag to indicate queue mode */
	bus.lifi = 1;
}


/**
 * addqueue - Adds a node to the tail of the queue.
 * @n: New value.
 * @head: Pointer to the head of the stack.
 *
 * Return: No return value.
 */

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}

	/* Set the new node's value and next pointer */
	new_node->n = n;
	new_node->next = NULL;

	/* If the stack is not empty, traverse to the tail */
	if (aux)
	{
		while (aux->next)
		aux = aux->next;
	}

	/* If the stack is empty, set the new node as the head */
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		/* Append the new node to the tail */
		aux->next = new_node;
		new_node->prev = aux;
	}
}
