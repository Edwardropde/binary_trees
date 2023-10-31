#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts leaves in binary tree
 * @tree: Pointer to root node of tree to count leaves
 * Return: Number of leaves on tree
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{

	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}