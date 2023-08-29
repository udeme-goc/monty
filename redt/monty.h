#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Structures */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct list_s
{
	char *inst;
	int n;
	struct list_s *next;
} list_t;

/* Global variable */
extern list_t *list_opcode;

/* Function prototypes */
void (*ptr_opcode(list_t *head))(stack_t **stack, unsigned int line_number);

int cmp_inst(char *str1, char *str2);
int cpy_arg(list_t *t, char *buff);
int check_arg(char *arg);
void check_file(char *str);
void core_stack_queue(stack_t **stack, unsigned int line_number, int sq);
void free_all(list_t *list, stack_t *stack);
void free_list_opcode(list_t *head);
void free_list_stack(stack_t *head);
int stack_len(stack_t *head);
void get_file(char *file_name);
void (*get_opcode(char *s, unsigned int line_number))(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void nothing(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

