#include "binary_trees.h"

/**
 * heap_extract - Entry point
 *
 * @root: root of the heap
 *
 * Return: 0 on success, error code on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *node;

	if (!root || !*root)
		return (0);
	value = (*root)->n;
	node = *root;
	while (node->left)
	{
		if (node->right)
		{
			if (node->left->n > node->right->n)
			{
				node->n = node->left->n;
				node = node->left;
			}
			else
			{
				node->n = node->right->n;
				node = node->right;
			}
		}
		else
		{
			node->n = node->left->n;
			node = node->left;
		}
	}
	if (node->parent)
	{
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
	}
	else
		*root = NULL;
	free(node);
	return (value);
}
