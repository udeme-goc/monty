#include "monty.h"

/**
 * _calloc - Allocates memory for an array, using malloc
 * @nmemb: Number of elements
 * @size: Size of bytes for each element
 *
 * Return: A pointer to the allocated memory, or NULL on failure
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	/* Check for valid input */
	if (nmemb == 0 || size == 0)
	return (NULL);

	/* Allocate memory using malloc */
	void *p = malloc(nmemb * size);

	/* Check if malloc failed */
	if (p == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");

		/* Clean up and exit */
		if (list_opcode)
		free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	/* Initialize memory to zero using memset */
	memset(p, 0, nmemb * size);

	/* Return the allocated memory */
	return (p);
}

