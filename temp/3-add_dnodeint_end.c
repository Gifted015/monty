#include "main.h"


/**
 *add_dnodeint_end - adds a new node at the beginning of a list
 *@head: doubly linked lists containing previously added nodes
 *@n: int to be added in new node
 *Return: the address of the new elment(node)
 *or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new = malloc(sizeof(dlistint_t)), *temp = *head;

if (new == NULL)
{
free(new);
return (NULL);
}

if (temp == NULL)
{
new->n = n;
new->prev = NULL;
new->next = NULL;

*head = new;
}

else
{
while (temp->next != NULL)
temp = temp->next;

new->n = n;
new->prev = temp;
new->next = NULL;

temp->next = new;
}

return (*head);
}
