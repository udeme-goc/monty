#include "monty.h"

/**
 * add_nodeint - Inserts a new node at the head of the stack
 * @head: Address to double linked list
 * @n: Value for the new node
 *
 * Return: Address of the new node, or NULL if it fails
 */

stack_t *add_nodeint(stack_t **head, const int n)
{
	stack_t *new;

	/* Check for valid head pointer */
	if (!head)
	{
		fprintf(stderr, "Error: invalid head pointer\n");

		/* Clean up and exit */
		free_list_opcode(list_opcode);
		free_list_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Allocate memory for the new node */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");

		/* Clean up and exit */
		free_list_opcode(list_opcode);
		free_list_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;

	*head = new;
	return (new);
}


/**
 * add_dnodeint_end - Adds a new node at the end of a linked list
 * @head: Head of the linked list
 * @n: Value for the new node
 *
 * Return: Address of the new node, or NULL if it fails
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new = NULL, *tmp = NULL;

	/* Check for valid head pointer */
	if (head == NULL)
	return (NULL);

	/* Allocate memory for the new node */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");

		/* Clean up and exit */
		free_list_opcode(list_opcode);
		free_list_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	tmp = *head;

	/* Traverse the list to find the last node */
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	new->prev = tmp;

	return (new);
}
