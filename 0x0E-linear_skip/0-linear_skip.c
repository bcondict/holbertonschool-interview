#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer on the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node = list;
	skiplist_t *prev = NULL;

	if (!list)
		return (NULL);

	while (node->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			node->express->index, node->express->n);
		if (node->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				node->index, node->express->index);
			break;
		}
		node = node->express;
	}
	if (!node->express)
	{
		prev = node;
		while (node->next)
			node = node->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, node->index);
		node = prev;
	}

	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		if (node->n > value)
			return (NULL);
		prev = node;
		node = node->next;
	}

	return (NULL);
}
