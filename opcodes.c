#include "monty.h"

/**
*opcodes - perform opcodes operations
*@stack: stack (doubly linked list) where num is to be stored
*@content: opcode instruction
*@num: number to be added to stack if instruction says so
*Return: x > 0 if opcode is executed successfully and 0 if otherwise
*/

int opcodes(stack_t **stack, char *content, __attribute__((unused)) int num)
{
int x = 0;
stack_t *temp = *stack;

if (strcmp(content, "push") == 0)
add_dnodeint(&temp, num), x++;

if (strcmp(content, "pall") == 0)
print_dlistint(temp), x++;

*stack = temp;
return (x);
}
