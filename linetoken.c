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
	size_t i, number;

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
		number = numberwords(buffer, r_line);
		tokenizer(buffer, tokens, number);
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
  * numberwords - Count the number of object were tokened
  * @buffer: buffer where is store the data line
  * @r_line: number of characters read it
  * Return: nothing
  */
size_t numberwords(char **buffer, ssize_t r_line)
{
	char *temp = NULL, *copybuffer = NULL, *delim = " \n\t";
	size_t i;

	copybuffer = malloc(sizeof(char) * r_line);
	strcpy(copybuffer, *buffer);
	temp = strtok(copybuffer, delim);
	for (i = 0; temp != NULL; i++)
		temp = strtok(NULL, delim);
	i++;
	free(copybuffer);
	if (i > 3)
		i = 3;
	return (i);
}
/**
  * tokenizer - Phrase the buffer in tokens
  * @buffer: buffer where is stored the data line
  * @tokens: where the opcode is stored
  * @number: number of tokens
  * Return: nothing
  */
void tokenizer(char **buffer, char ***tokens, size_t number)
{
	char *token = NULL, *delim = " \n\t";
	size_t i;

	token = strtok(*buffer, delim);
	if (strcmp(token, "push") == 0)
		number = 1;
	else
		number = 0;
	*tokens = malloc(sizeof(char *) * number);
	for (i = 0; token != NULL && i <= number; i++)
	{
		(*tokens)[i] = token;
		token = strtok(NULL, delim);
	}
	(*tokens)[i] = NULL;
}
