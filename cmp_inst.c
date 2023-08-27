#include "monty.h"

/**
 * cmp_inst - Compares two strings up to the length of the second string
 * @str1: First string to compare
 * @str2: Second string to compare
 *
 * Return: 0 if the strings are equal, a positive value if str1 is greater,
 * or a negative value if str2 is greater
 */

int cmp_inst(char *str1, char *str2)
{
	int i = 0, n = 0;

	/* Compare characters up to the length of str2 */
	for (i = 0; str2[i]; i++)
	{
		if (str1[i] == str2[i])
		n = 0;
		else
		{
			n = str1[i] - str2[i];
			break;
		}
	}

	/* Handle cases where str1 is longer or there is additional content */
	if (str1[i] != ' ' && str1[i] != '\t' && str1[i] != '\0' && str1[i] != '\n')
		n = 1;

	return (n);
}
