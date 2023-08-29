#include "monty.h"

/**
 * check_file - Checks if the file has a .m extension
 * @str: String to be checked
 */

void check_file(char *str)
{
	int len;

	len = _strlen(str);

	/* Check if the last character of the filename is 'm' */
	if (str[len - 1] != 'm')
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);

		/* Clean up and exit */
		free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}
}
