#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular
 *               linked list
 *
 * @list: A pointer to the head of the double circular linked list
 * @str: The string to copy into the new node
 *
 * Return: A pointer to the newly added node, or NULL on failure
*/
List *add_node_end(List **list, char *str)
{
	List *node = NULL;
	List *last_node = *list;

	if (list == NULL)
		return (NULL);

	node = malloc(sizeof(char));
	if (node == NULL)
		return (NULL);

	node->str = strdup(str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->prev = NULL;

	if (*list == NULL)
	{
		node->next = node;
		node->prev = node;
		*list = node;
		return (node);
	}

	last_node = (*list)->prev;
	node->prev = last_node;
	node->next = *list;
	last_node->next = node;
	(*list)->prev = node;

	return (node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular
 *                  linked list
 *
 * @list: A pointer to the head of the double circular linked list
 * @str: The string to copy into the new node
 *
 * Return: A pointer to the newly added node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node = NULL;
	List *last_node = *list;

	if (list == NULL)
		return (NULL);

	node = malloc(sizeof(char));
	if (node == NULL)
		return (NULL);

	node->str = strdup(str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->prev = NULL;

	if (*list == NULL)
	{
		node->next = node;
		node->prev = node;
		return (node);
	}

	last_node = (*list)->prev;
	node->prev = last_node;
	node->next = *list;
	(*list)->prev = node;
	last_node->next = node;

	return (node);
}
