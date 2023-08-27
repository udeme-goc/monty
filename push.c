#include "monty.h"

/**
 * push - Pushes a new node onto the stack
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 *
 * This function pushes a new node onto the stack using the core_stack_queue
 * function with the mode 0.
 */

void push(stack_t **stack, unsigned int line_number)
{
	core_stack_queue(stack, line_number, 0);
}


/**
 * stack - Sets the stack mode
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 *
 * This function sets the stack mode using the core_stack_queue function
 * with the mode 1.
 */

void stack(stack_t **stack, unsigned int line_number)
{
	core_stack_queue(stack, line_number, 1);
}


/**
 * queue - Sets the queue mode
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the instruction
 *
 * This function sets the queue mode using the core_stack_queue function
 * with the mode 2.
 */

void queue(stack_t **stack, unsigned int line_number)
{
	core_stack_queue(stack, line_number, 2);
}
