#include "lists.h"

/**
 * check_cycle - check if a single linked list has a cycle in it
 *
 * @list: Pointer head to single linked list
 *
 * Return: 0 if there's ino cycle, 1 if there's a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *speed = NULL;
	listint_t *normal = NULL;

	if (!list || !list->next)
		return (0);

	normal = list;
	speed = list->next;

	while (speed && speed->next)
	{
		if (normal == speed)
			return (1);
		normal = normal->next;
		speed = speed->next->next;
	}

	return (0);
}
