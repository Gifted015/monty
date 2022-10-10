#include "monty.h"

#define MAX_LINE_LENGTH 80

/**
 *main - an interpreter for Monty ByteCodes file
 *@argv: argument vector
 *@argc: argument count
 *Return: 0
 */

int main(int argc, char **argv)
{
FILE *f;
__attribute__((unused)) char *content, *file_name, *line, *file;
__attribute__((unused)) unsigned int x;
__attribute__((unused)) int num;
__attribute__((unused)) stack_t *stack;
__attribute__((unused)) instruction_t *instruct;

if (argc != 2)
usage_error();

file_name = argv[1];
f = fopen(file_name, "r");
if (f == NULL)
open_error(file_name);

stack = NULL;
content = malloc(sizeof(char) * 5);
if (content == NULL)
malloc_error(content);

line = malloc(sizeof(char) * MAX_LINE_LENGTH);
if (line == NULL)
malloc_error(line);

for (x = 1; fgets(line, MAX_LINE_LENGTH, f); x++)
{
while (fscanf(f, " %s %d ", content, &num) != -1)
{
if (strcmp(content, "push") == 0)
add_dnodeint(&stack, num);
else if (strcmp(content, "pall") == 0)
print_dlistint(stack);
else
unknown_instruction(f, stack, content, line, x);
}
}

free_dlistint(stack);
free(content), free(line);
fclose(f);
return (0);
}
