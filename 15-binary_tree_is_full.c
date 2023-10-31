#include "binary_trees.h"

/**
 * is_full_recursive - Checks if binary tree is full recursively
 * @tree: Pointer to root node of tree to check
 * Return: 1 if tree if full. 0 if otherwise
 */

int is_full_recursive(const binary_tree_t *tree)
{

	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
			(tree->left == NULL && tree->right != NULL) ||
			is_full_recursive(tree->left) == 0 ||
			is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if binary tree is full
 * @tree: ointer to root node of tree to check
 * Return: 1 if tree is full 0 if tree is not full or NULL.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}