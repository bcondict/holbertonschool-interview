#include "lists.h"

/**
 * insert_node - inser a number into a sorted singly linked list
 * @head: doble pointer to head node
 * @number: value to intert into sorted singly linked list
 *
 * Return: Address of the new node, NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL;
	listint_t *temp = NULL;
	listint_t *current = NULL;

	temp = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return NULL;

	new_node->n = number;

	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}

	if (temp->n > number)
	{
		new_node->next = temp;
		*head = new_node;
		return (new_node);
	}

	while (temp && temp->n < number)
	{
		current = temp;
		temp = temp->next;
	}

	current->next = new_node;
	new_node->next = temp;

	return (new_node);
}
