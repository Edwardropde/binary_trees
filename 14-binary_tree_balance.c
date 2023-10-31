#include "binary_trees.h"

/**
 * binary_tree_balance - Determines the binary tree's balance factor
 * @tree: Pointer to root node of tree to determine balance factor
 * Return: Balance factor ir 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{

	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	return (0);
}

/**
 * binary_tree_height - Measures height of binary tree.
 * @tree: Pointer to root node of tree to Measure height
 * Return: Height or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{

	size_t left = 0, right = 0;

	if (tree)
	{
		left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}
