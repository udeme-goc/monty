#include "monty.h"

/**
 * f_push - Adds a node to the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 *
 * Return: No return value.
 */

void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	/* Check if an argument is provided */
	if (bus.arg)
	{
		/* Handle negative numbers */
		if (bus.arg[0] == '-')
		j++;

		/* Check if the argument is a valid integer */
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
			flag = 1;
		}

		/* If the argument is not a valid integer */
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Convert the argument to an integer */
	n = atoi(bus.arg);

	/* Determine whether to add the node to the stack or queue */
	if (bus.lifi == 0)
		addnode(head, n); /* Add to stack */
	else
		addqueue(head, n); /* Add to queue */
}
