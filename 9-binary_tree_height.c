#include "binary_trees.h"

/**
 * binary_tree_height - Measures binary tree height
 * @tree: Pointer to root node of binary tree whose height is measured
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{

	size_t left = 0, right = 0;

	if (tree)
	{
		left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((left > right) ? left : right);
	}
	return (0);
}
