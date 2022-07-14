#include "monty.h"

/**
  * inter_monty - Monty Interpreter
  * @av: argument vector
  * Return: nothing
  */
void inter_monty(char **av)
{
	char *file = av[1], *buffer = NULL, **tokens = NULL;
	size_t len = 0, linu = 1;
	ssize_t r_line;
	stack_t *st_stack = NULL;
	FILE *open_f;

	open_f = fopen(file, "r");

	if (open_f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	for (linu = 1; (r_line = getline(&buffer, &len, open_f)) != -1; linu++)
	{
		token_line(&buffer, &tokens, r_line);
		if (tokens != NULL)
			opcode_choose(&st_stack, &tokens, linu);
		freetokens(&tokens);
	}

	fclose(open_f);
	if (buffer != NULL)
		free(buffer);
	freest_stack(st_stack);
}
/**
  * freetokens - Free the tokens
  * @tokens: tokens to free
  * Return: nothing
  */
void freetokens(char ***tokens)
{
	if (*tokens != NULL)
	{
		free(*tokens);
		*tokens = NULL;
	}
}
/**
  * freest_stack - Free the stack
  * @st_stack: Stack to free
  * Return: nothing
  */
void freest_stack(stack_t *st_stack)
{
	stack_t *savepoin;

	if (st_stack != NULL)
	{
		while (st_stack != NULL)
		{
			savepoin = st_stack->next;
			free(st_stack);
			st_stack = savepoin;
		}
	}
}
