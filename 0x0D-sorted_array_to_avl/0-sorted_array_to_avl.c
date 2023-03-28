#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array 
 *
 * Return: avl_t* pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t mid = 0;

	if (!array || size == 0)
		return NULL;

	root = malloc(sizeof(avl_t));
	if (!root)
		return NULL;

	mid = (size / 2) ;
	root->n = array[mid];
	root->parent = NULL;
	root->left = sorted_array_to_avl(array, mid);
	root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	return root;
}
