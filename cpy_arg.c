#include "monty.h"

/**
 * cpy_arg - Copies the argument of push instruction into a buffer
 * @t: Pointer to the linked list node containing the instruction
 * @buff: Buffer to store the copied argument
 *
 * Return: Length of the copied argument, or 0 if it fails
 */

int cpy_arg(list_t *t, char *buff)
{
	int i, j;

	/* Initialize the buffer */
	for (i = 0; i < 10024; i++)
		buff[i] = 0;

	/* Copy the argument from the instruction */
	for (i = 5, j = 0; t->inst[i] != '\0' && t->inst[i] != ' '; i++, j++)
		buff[j] = t->inst[i];

	buff[j] = '\0';  /* Null-terminate the copied argument */

	return (j);
}
