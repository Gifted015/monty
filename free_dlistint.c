#include "monty.h"

/**
 *free_dlistint - frees a stack_t list
 *@head: doubly linnked list containing elements to be freed
 *Return: nothing
 */

void free_dlistint(stack_t *head)
{
stack_t *temp;

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
