#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Determines if leaf is tree or binary tree
 * @node: Pointer to node to be checked
 * Return: 1 if node is leaf, 0 otherwise
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{

	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);
	return (1);
}
