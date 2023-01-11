#include "binary_trees.h"

/**
 * heap_insert - insters a value into a Max Binary Heap 
 *
 * @root: doble pointer to the root node of the heap
 * @value: is the value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;

	new_node = binary_tree_node(*root, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	/*checks if left node of root is empty or not */
	// if (!(*root)->left)
	// {
	// 	heap_insert((*root)->left, value);

	// }

	return (new_node);
}
