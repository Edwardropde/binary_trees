#include "binary_trees.h"

/**
 * binary_tree_uncle - Locates uncle of a node in binary tree
 * @node: Pointer to node to locate uncle of
 * Return: A pointer to the uncle node, if node is null or no uncle then
 * NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{

	if (node == NULL ||
		node->parent == NULL ||
		node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
