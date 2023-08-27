#include "monty.h"

/**
 * core_stack_queue - Manages stack and queue behavior
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 * @sq: Switch for stack and queue behavior (0 = push, 1 = stack, 2 = queue)
 *
 * This function manages whether to push elements onto the stack or queue based
 * on the value of the `sq` parameter. It uses other functions and global
 * variables to achieve the desired behavior.
 */

void core_stack_queue(stack_t **stack, unsigned int line_number, int sq)
{
	static int turn;
	int i, j;
	char buff[10024];
	char *b = buff;
	list_t *t = NULL;

	/* Handle switching between stack and queue modes */
	if (sq != 0)
	{
		turn = sq;
		return;
	}

	t = list_opcode;

	/* Find the instruction in the list of opcodes */
	for (; t->next; t = t->next)
		if (t->n == (int) line_number)
			break;

	i = cpy_arg(t, b);

	j = check_arg(b);

	/* Print an error and exit if the argument is missing or invalid */
	if (i == 0 || j == 0)
		print_error_push(stack, line_number);

	/* Perform the appropriate action based on stack and queue modes */
	if (turn == 1)
		add_nodeint(stack, atoi(buff));  /* Stack mode */
	else if (turn == 2)
		add_dnodeint_end(stack, atoi(buff));  /* Queue mode */
	else
		add_nodeint(stack, atoi(buff));  /* Default behavior (push to stack) */
}


/**
 * print_error_push - Prints an error message for push instruction
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 *
 * This function prints an error message when the push instruction is not used
 * with a valid integer argument. It also frees memory and exits with failure.
 */

void print_error_push(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	if (*stack)
		free_list_stack(*stack);
	if (list_opcode)
		free_list_opcode(list_opcode);
	exit(EXIT_FAILURE);
}
