#include "lists.h"

/**
 * is_palindrome - Function checks if a singly linked list is a palindrome
 * @head: Head of the single linked list.
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	listint_t *temp = NULL;
	int *array;
	int i, lenght = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		lenght++;
	}
	array = malloc(lenght * sizeof(int));
	temp = *head;
	for (i = lenght - 1; i >= 0; i--)
	{
		array[i] = temp->n;
		temp = temp->next;
	}
	temp = *head;
	for (i = 0; i < lenght - 1; i++)
	{
		if (array[i] != temp->n)
		{
			free(array);
			return (0);
		}
		temp = temp->next;
	}
	free(array);
	return (1);
}
