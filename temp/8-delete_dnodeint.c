#include "emacs.h"

/**
 *delete_dnodeint_at_index - deletes the node at index of a doubly linked list
 *@head: the doubly linked list head
 *@index: index of the node to be deleted
 *Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *temp = *head, *new;
unsigned int x = 0;
while (temp != NULL)
{
if (x == index)
break;
temp = temp->next, x++;
}
if (x == index)
{
if (temp == NULL)
return (-1);
else
{
new = temp->prev;
if (new != NULL)
new->next = temp->next;
if (temp->next != NULL)
{
temp->next->prev = new;
new = temp->next;
}

if (new != NULL)
{
while (new->prev != NULL)
new = new->prev;
}
free(temp);
*head = new;
}
return (1);
}
else
return (-1);
}
