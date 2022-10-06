#include "main.h"


/**
 *new_node - helps in inserts a new node at a given position
 *@temp: the head of the doubly linked list
 *@idx: index of temp indicating the postion for new node to be added
 *@n: integer to be added in new node
 *@x: current index
 *Return: the address of the new node
 */


dlistint_t *new_node(dlistint_t *temp, unsigned int idx, int n, unsigned int x)
{
dlistint_t *new;

if (x == idx)
{
new = malloc(sizeof(dlistint_t));
if (new == NULL)
{
free(new);
return (NULL);
}

new->n = n;

if (temp == NULL)
new->prev = NULL;
else
new->prev = temp->prev, temp->prev = new;

new->next = temp;
}

else if (x + 1 == idx)
{
new = malloc(sizeof(dlistint_t));
if (new == NULL)
{
free(new);
return (NULL);
}

new->n = n;

if (temp == NULL)
new->prev = NULL;
else
temp->next = new->prev = temp;

new->next = NULL;
}
return (new);
}

/**
 *insert_dnodeint_at_index - inserts a new node at a given position
 *@h: pointer to the head of the doubly linked list
 *@idx: index of h indicating the postion for new node to be added
 *@n: integer to be added in new node
 *Return: the address of the new node
 *or NULL if it failed or its not possible to add the new node at the index idx
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *temp = NULL, *new, *ret = NULL;
unsigned int x = 0;

temp = *h;
while (temp != NULL)
{
if (x == idx)
break;

if (x + 1 == idx && temp->next == NULL)
break;

temp = temp->next;
x++;
}

new = malloc(sizeof(dlistint_t));
if (new == NULL)
{
free(new);
return (NULL);
}

new = new_node(temp, idx, n, x);
temp = new;

if (x == idx || x + 1 == idx)
{
while (new->prev != NULL)
{
ret = new;
new = new->prev;
new->next = ret;
}
*h = new;
return (temp);
}

return (NULL);
}
