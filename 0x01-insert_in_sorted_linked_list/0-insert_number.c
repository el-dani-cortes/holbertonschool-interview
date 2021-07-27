#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - Insert a node by order in the sorted linked list
 * @head: pointer to head of linked list
 * @number: data number to insert in the linked list
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *ahead = NULL, *behind = NULL, *new_node = NULL;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	behind = *head;
	ahead = behind->next;
	new_node->n = number;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	if (number <= behind->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	while (ahead != NULL)
	{
		if (ahead->n >= number && ahead->next != NULL)
		{
			new_node->next = ahead;
			behind->next = new_node;
			return (new_node);
		}
		if (ahead->n < number && ahead->next == NULL)
		{
			new_node->next = NULL;
			ahead->next = new_node;
			return (new_node);
		}
		behind = behind->next;
		ahead = ahead->next;
	}
	return (NULL);
}
