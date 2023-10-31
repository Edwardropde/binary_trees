#include "binary_trees.h"

/**
 * binary_tree_is_root - Determines if node is root or binary tree
 * @node: Pointer to node to be checked
 * Return: 1 if node is a root. 0 if otherwise
 */

int binary_tree_is_root(const binary_tree_t *node)
{

	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
