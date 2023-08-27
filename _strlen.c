#include "monty.h"

/**
 * _strlen - Calculates the length of a string
 * @str: String to be checked
 *
 * Return: The length of the string, or -1 if the input is NULL
 */

int _strlen(char *str)
{
	int i;

	/* Check for NULL input string */
	if (str == NULL)
		return (-1);

	/* Calculate the length of the string */
	for (i = 0; str[i] != '\0'; i++)
	{
		/* Loop body intentionally left blank */
	}

	return (i);
}
