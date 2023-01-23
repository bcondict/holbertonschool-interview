#include "lists.h"

/**
 * linked_list_len - check the length of a linked list
 *
 * @head: linked list to check length 
 *
 * Return: length of linked list
 */
int linked_list_len(listint_t **head)
{
	int size = 1;
	listint_t *temp = *head; 
	while (temp->next != NULL)
	{
		size += 1;
		temp = temp->next;
	}
	return size;
}

/**
 * to_array - turn a linked list to an array
 *
 * @head: pointer head of Linked list
 * @size: size or length of linked list
 *
 * Return: an array of a given linked list
 */
int *to_array(listint_t **head, int size)
{
	int *new_array = NULL;
	int i = 0;

	new_array = malloc(sizeof(int) * size);
	if (new_array == NULL)
		return (NULL); 

	listint_t *temp = *head;
	for (i = 0; i < size; i++)
	{
		new_array[i] = temp->n;
		temp = temp->next;
	}

	return (new_array);
}

/**
 * is_palindrome - check if a single linked list is palindrome
 * @head: double pointer, head of single linked list
 *
 * Return: 0 if is not palindrome, 1 if it's a palindrome 
 */

int is_palindrome(listint_t **head)
{
	int size = 0;
	int i = 0;
	int *new_array = NULL;

	if (*head == NULL)
		return (1);

	size = linked_list_len(head);
	i = 0;
	*new_array = to_array(head, size); 

	if (size == 1)
		return (1);

	size = size - 1;
	for (i = 0; i < size; i++)
	{
		if (new_array[i] != new_array[size - i])
			return (0);
	}

	free(new_array);
	return (1);
}
