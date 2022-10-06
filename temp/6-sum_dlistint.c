#include "main.h"

/**
 *sum_dlistint - find the sum of all the data(n) of a linked list
 *@head: the doubly linnked list
 *Return: the sum or 0 if the list is empty
 */

int sum_dlistint(dlistint_t *head)
{
int x = 0;

if (head == NULL)
return (0);

while (head != NULL)
{
x = x + head->n;
head = head->next;
}

return (x);
}
