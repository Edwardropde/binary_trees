#include "binary_trees.h"

/**
 * binary_tree_depth - Measures depth of node in binary tree
 * @tree: Pointer to node to measure depth
 * Return: Return depth. If tree is null return 0.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{

	if (tree == NULL || tree->parent == NULL)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
