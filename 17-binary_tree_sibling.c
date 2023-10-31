#include "binary_trees.h"

/**
 * binary_tree_sibling - Find sibling of node in binary tree
 * @node: Pointer to node to find sibling
 * Return: Pointer to sibling or null of node is NUll of no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{

	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
