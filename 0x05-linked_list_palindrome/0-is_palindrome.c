#include "lists.h"

/**
 * is_palidrome - Function checks if a singly linked list is a palindrome
 * @head: Head of the single linked list.
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	listint_t *behind = NULL, *advance = NULL;
	unsigned int lenght = 0, position = 0, i = 0;

	advance = *head;
	while (advance)
	{
		advance = advance->next;
		lenght++;
	}
	behind = *head;
	while (position != lenght / 2)
	{
		advance = *head;
		if (position != 0)
			behind = behind->next;
		for (i = 0; i < lenght - (position + 1); i++)
			advance = advance->next;
		if (advance->n != behind->n)
			return (0);
		position++;
	}
	return (1);
}