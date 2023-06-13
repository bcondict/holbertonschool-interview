#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: address of the node where the loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = NULL;
	listint_t *fast = NULL; 

	if (!head || !head->next)
		return (NULL);

	fast = head->next->next;
	slow = head->next;
	while (fast && fast->next)
	{
		if (fast == slow)
			break;
		fast = fast->next->next;
		slow = slow->next;
	}

	if (slow != fast)
		return (NULL);

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);
}
