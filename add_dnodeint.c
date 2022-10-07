#include "monty.h"


/**
 *add_dnodeint - adds a new node at the beginning of a list
 *@head: doubly linked lists containing previously added nodes
 *@n: int to be added in new node
 *Return: the address of the new elment(node)
 *or NULL if it failed
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
stack_t *new = malloc(sizeof(stack_t));

if (new == NULL)
{
free(new);
return (NULL);
}

new->n = n;
new->prev = NULL;

if (*head != NULL)
(*head)->prev = new;

new->next = *head;

*head = new;

return (*head);
}
