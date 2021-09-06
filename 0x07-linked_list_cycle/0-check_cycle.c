#include "lists.h"
/**
 * check_cycle - Function that check if is a loop inside linked list
 * @list: pointer to head of list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *advance = list;

	if (!list || !list->next)
		return (0);
	while (advance && list && advance->next)
	{
		advance = advance->next->next;
		list = list->next;
		if (advance == list)
			return (1);
	}
	return (0);
}