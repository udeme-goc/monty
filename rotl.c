#include "monty.h"

/**
 * f_rotl - Rotates the stack to the top.
 * @head: Pointer to the stack's head.
 * @counter: Line number (unused).
 *
 * Return: No return value.
 */

void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	/* If the stack is empty or has only one element, no rotation needed */
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	aux = (*head)->next;
	aux->prev = NULL;

	/* Traverse to the end of the stack */
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	/* Rotate the stack to the top */
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
