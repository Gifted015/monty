#include "main.h"

/**
 *dlistint_len - returns the number of elements of a dlistint_t list
 *@h: doubly linnked list containing elements to be counted
 *Return: the number of the elements in h
 */

size_t dlistint_len(const dlistint_t *h)
{
dlistint_t *temp = (dlistint_t *)h;
int x = 0;

while (temp != NULL)
{
temp = temp->next;
x++;
}

return (x);
}
