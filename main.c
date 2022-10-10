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
__attribute__((unused)) char *content, *file_name, *line, *file, *temp, *check;
__attribute__((unused)) unsigned int x;
__attribute__((unused)) int num, ret, a, b;
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

check = malloc(sizeof(char) * MAX_LINE_LENGTH);
if (check == NULL)
malloc_error(check);

for (x = 1; fgets(line, MAX_LINE_LENGTH, f); x++)
{
for(a = 0; line[a] != '\n'; a++)
{
if (line[a] != ' ' )
{
for (b = 0; line[a] != ' '; b++, a++)
{
if (line[a] == '\n')
break;
content[b] = line[a];
}
}

while(line[a] == ' ')
a++;

if (line[a] != ' ')
{
temp = malloc(sizeof(char) * MAX_LINE_LENGTH);
if (temp == NULL)
malloc_error(temp);
for (b = 0; line[a] != ' '; b++, a++)
{
if (line[a] == '\n')
break;
temp[b] = line[a];
}
num = atoi(temp);
sprintf(check, "%d", num);
if (strcmp(temp, check) != 0 || temp == NULL)
push_error(f, stack, content, line, x);
}
ret = opcodes(&stack, content, num);
if (ret == 0)
unknown_error(f, stack, content, line, x);

if (line[a] == '\n')
break;
}
temp = NULL;
}
free_dlistint(stack);
free(content), free(line);
fclose(f);
return (0);
}
