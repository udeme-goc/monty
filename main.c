#include "monty.h"

list_t *list_opcode = NULL;  /* Global variable for the list of opcodes */

/**
 * main - Main entry point for the Monty interpreter
 * @argc: Argument count for the command line
 * @argv: Argument vector for the command line
 *
 * This function is the main entry point for the Monty interpreter. It checks
 * the command line arguments, reads and processes the Monty bytecode file,
 * and executes the instructions accordingly.
 *
 * Return: 0 on success, or an exit code if an error occurs
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;  /* Stack for processing instructions */
	list_t *temp;  /* Temporary pointer to traverse the opcode list */

	/* Check for the correct number of command line arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Check if the file has the correct extension */
	check_file(argv[1]);

	/* Read and process the Monty bytecode file */
	get_file(argv[1]);

	/* Traverse the opcode list and execute instructions */
	temp = list_opcode;
	for (; temp; temp = temp->next)
		(*ptr_opcode(temp))(&stack, temp->n);

	/* Clean up and exit */
	free_all(list_opcode, stack);
	return (0);
}
