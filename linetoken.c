#include "monty.h"

/**
  * token_line - start the monty interpreter
  * @buffer: buffer where will store the data line
  * @tokens: where the opcode will be stored
  * @r_line: number of characters read it
  * Return: nothing
  */

void token_line(char **buffer, char ***tokens, ssize_t r_line)
{
	size_t i;

	if (r_line > 0)
	{
		for (i = 0; (*buffer)[i] == ' ' || (*buffer)[i] == '\t'; i++)
		{
			if ((*buffer)[i + 1] == '\n')
				return;
		}
	}

	if (**buffer != '\n')
	{
		deletenl(buffer);
		tokenizer(buffer, tokens);
	}
}
/**
  * deletenl - Delete the newline
  * @buffer: buffer where is stored the data line
  * Return: nothing
  */
void deletenl(char **buffer)
{
	int i;

	for (i = 0; (*buffer)[i] != '\0'; i++)
		;
	(*buffer)[i - 1] = '\0';
}
/**
  * tokenizer - Phrase the buffer in tokens
  * @buffer: buffer where is stored the data line
  * @tokens: where the opcode is stored
  * Return: nothing
  */
void tokenizer(char **buffer, char ***tokens)
{
	char *token = NULL, *delim = " \n\t";
	size_t i, number;

	token = strtok(*buffer, delim);
	if (strcmp(token, "push") == 0)
		number = 3;
	else
		number = 2;
	*tokens = malloc(sizeof(char *) * number);
	for (i = 0; token != NULL && i <= number - 2; i++)
	{
		(*tokens)[i] = token;
		token = strtok(NULL, delim);
	}
	(*tokens)[i] = NULL;
}
