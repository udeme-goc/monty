#include "monty.h"

/**
 * pstr - Prints a string of characters from the stack
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction (unused)
 *
 * Function prints the string of characters represented by the ASCII values
 * stored in the stack. It stops printing when a null byte (ASCII 0) is reached
 * or if a non-printable character is encountered.
 */

void pstr(stack_t **stack, UN unsigned int line_number)
{
	stack_t *temp = NULL;

	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		putchar(10);  /* Print a newline */
		return;
	}

	temp = *stack;

	/* Traverse the stack and print characters */
	while (temp)
	{
		/* Check if the ASCII value is out of printable range or null byte */
		if ((temp->n < 0 || temp->n > 126) || temp->n == 0)
		{
			putchar(10);  /* Print a newline */
			return;
		}

		/* Print the character corresponding to the ASCII value */
		printf("%c", temp->n);
		temp = temp->next;
	}

	putchar(10);  /* Print a newline */
}
