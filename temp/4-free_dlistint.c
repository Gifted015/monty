#include "main.h"

/**
 *free_dlistint - frees a dlistint_t list
 *@head: doubly linnked list containing elements to be freed
 *Return: nothing
 */

void free_dlistint(dlistint_t *head)
{
dlistint_t *temp;

if (head != NULL)
{
while (head->next != NULL)
{
temp = head;
head = head->next;
free(temp);
}
free(head);
}
}
