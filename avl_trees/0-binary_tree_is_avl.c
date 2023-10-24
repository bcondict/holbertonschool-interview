#include "binary_trees.h"


/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left;
	int right;

	if (!tree)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (abs(left - right) > 1)
		return (0);
	else
		return (1);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}

/**
 * max - Returns the maximum value between two integers
 *
 * @a: First integer
 * @b: Second integer
 *
 * Return: The maximum value between @a and @b
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}


/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree starting at @tree
*/
int binary_tree_height(const binary_tree_t *tree)
{
	int height_l;
	int height_r;

	if (!tree)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);

	return (max(height_l, height_r) + 1);
}

