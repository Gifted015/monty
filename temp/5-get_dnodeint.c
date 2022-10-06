#include "main.h"

/**
 *get_dnodeint_at_index - returns the nth node of dlistint_t linked list
 *@head: the doubly linnked list
 *@index: index of the node to be returned
 *Return: the nth node(pointer to it)
 *or NULL if the node does not exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
dlistint_t *temp = head;
unsigned int x = 0;

while (temp != NULL)
{
if (x == index)
break;

temp = temp->next;
x++;
}

if (x == index)
return (temp);
else
return (NULL);
}
