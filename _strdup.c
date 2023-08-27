#include "monty.h"

/**
 * _strdup - Returns pointer to newly allocatd memory containing copy of string
 * @str: String to be duplicated
 * @fp: Pointer to the open file
 *
 * Return: A pointer to the duplicated string, or NULL if it fails
 */

char *_strdup(char *str, FILE *fp)
{
	int i;
	char *new;

	/* Check for NULL input string */
	if (str == NULL)
	return (NULL);

	/* Get the length of the input string */
	i = _strlen(str);

	/* Allocate memory for the duplicated string */
	new = _calloc(i + 1, sizeof(char));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");

		/* Clean up and exit */
		if (list_opcode)
			free_list_opcode(list_opcode);
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	/* Copy characters from the input string to the new memory */
	for (i = 0; str[i] != '\0'; i++)
		new[i] = str[i];

	new[i] = '\0';  /* Add the null-terminator to the new string */

	return (new);
}
