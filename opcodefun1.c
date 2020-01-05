#include "monty.h"

/**
  * pushS - push a number in a stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */

void pushS(stack_t **st_stack, unsigned int linu)
{
	stack_t *new = malloc(sizeof(stack_t));
	(void) linu;

	if (new == NULL)
		return;
	new->n = num;
	new->prev = NULL;
	new->next = NULL;
	if (*st_stack != NULL)
	{
		new->next = *stack;
		(*st_stack)->prev = new;
	}
	*st_stack = new;
}
/**
  * printS - print the stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void printS(stack_t **st_stack, unsigned int linu)
{
	stack_t *save = *st_stack;

	(void) linu;
	if (*st_stack == NULL)
		return;
	while (save != NULL)
	{
		printf("%d\n", save->n);
		save = save->next;
	}
}
