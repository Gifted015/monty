#include "monty.h"

/**
 *main - an interpreter for Monty ByteCodes file
 *@argv: argument vector
 *@argc: argument count
 *Retrun 
 */

#define MAX_LINE_LENGTH 80

int main(int argc, char **argv)
{
  FILE *f;
  __attribute__((unused)) char *content, *file_name, *line;
  __attribute__((unused)) unsigned int x;
  __attribute__((unused)) int num;
  __attribute__((unused)) stack_t *stack;
  __attribute__((unused)) instruction_t *instruct;

  if (argc != 2)
    {
      printf("USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }
  file_name = argv[1];
  f = fopen(file_name, "r");
  if (f == NULL)
    {
      printf("Error: Can't open file %s\n", file_name);
      exit(EXIT_FAILURE);
    }


  stack = NULL;
  content = malloc(sizeof(char) * 5);
  if (content == NULL)
    {
      printf("Error: malloc failed\n");
      exit(EXIT_FAILURE);
    }
  line = malloc(sizeof(char) * MAX_LINE_LENGTH);
  if (line == NULL)
    {
      printf("Error: malloc failed\n");
      exit(EXIT_FAILURE);
    }
  for (x = 0; fgets(line, MAX_LINE_LENGTH, f); x++)
    {
      while (fscanf(f, " %s %d ", content, &num) != -1)
	{
	  printf("%s %d\n", content, num);
	  if (strcmp(content, "push") == 0)
	    add_dnodeint(&stack, num);
	  else if (strcmp(content, "pall") == 0)
	    print_dlistint(stack);
	  else
	    {
	      printf("L%d: unknown instruction %s\n", x + 1, content);
	      free_dlistint(stack);
	      free(content), free(line);
	      fclose(f);
	      exit(EXIT_FAILURE);
	    }
	}
    }

  free_dlistint(stack);
  free(content), free(line);
  fclose(f);
  return (0);
}
