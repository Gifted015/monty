#include "monty.h"


/**
*usage_error - handles error for wrong usage of monty command
*Return: nothing
*/

void usage_error(void)
{
char *text = "USAGE: monty file\n";
write(2, text, sizeof(char) * strlen(text));
exit(EXIT_FAILURE);
}


/**
*open_error - handles error occured in opening of file
*@file_name: file name
*Return: nothing
*/

void open_error(char *file_name)
{
char text[80];
sprintf(text, "Error: Can't open file %s\n", file_name);
write(2, text, sizeof(char) * strlen(text));
exit(EXIT_FAILURE);
}


/**
*malloc_error - handle malloc allocation error
*@holder: buffer to which malloc failed to allocate space for
*Return: nothing
*/

void malloc_error(char *holder)
{
char *text = "Error: malloc failed\n";
write(2, text, sizeof(char) * strlen(text));
free(holder);
exit(EXIT_FAILURE);
}


/**
*unknown_error - handles error as a result of unknown instruction in file
*@f: file being run
*@stack: stack (doubly linked list) previously created
*@content: the unknown instruction
*@line: line in file where wrong instruction was found
*@x: line number in file
*Return nothing
*/

void unknown_error(FILE *f, stack_t *stack, char *content, char *line, int x)
{
char text[80];
sprintf(text, "L%d: unknown instruction %s\n", x, content);
write(2, text, sizeof(char) * strlen(text));
free_dlistint(stack);
free(content), free(line);
fclose(f);
exit(EXIT_FAILURE);
}


/**
*push_error - handles error resulting from wrong usage of push
*@f: file being run
*@stack: stack (doubly linked list) previously created
*@content: buffer holding instruction push
*@line: line in file where push was used
*@x: line number in file
*Return nothing
*/

void push_error(FILE *f, stack_t *stack, char *content, char *line, int x)
{
char text[80];
sprintf(text, "L%d: usage: push integer\n", x);
write(2, text, sizeof(char) * strlen(text));
free_dlistint(stack);
free(content), free(line);
fclose(f);
exit(EXIT_FAILURE);
}
