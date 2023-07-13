#include "list.h"

/**
 * create_node - Create a new node
 *
 * @str: The string to copy into the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
List *create_node(char *str)
{
	List *node = NULL;

	node = malloc(sizeof(List));
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

	return (node);
}

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

	node = create_node(str);
	if (node == NULL)
		return (NULL);

	if (*list == NULL)
	{
		node->next = node;
		node->prev = node;
		*list = node;
	}

	else
	{
		node->prev = (*list)->prev;
		node->next = *list;
		(*list)->prev->next = node;
		(*list)->prev = node;
		*list = node;
	}

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

	node = create_node(str);
	if (node == NULL)
		return (NULL);

	if (*list == NULL)
	{
		node->next = node;
		node->prev = node;
		return (node);
	}

	else
	{
		node->prev = (*list)->prev;
		node->next = *list;
		(*list)->prev = node;
		(*list)->prev->next = node;
	}

	return (node);
}
