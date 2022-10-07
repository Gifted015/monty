#include "monty.h"

/**
 *print_dlistint - prints all elements of a stack_t list
 *@h: doubly linnked list containing elements to be printed
 *Return: the number of nodes in h
 */

size_t print_dlistint(const stack_t *h)
{
stack_t *temp = (stack_t *)h;
int x = 0;

while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
x++;
}

return (x);
}
