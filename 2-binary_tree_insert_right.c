#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert node at right-child of binary tree
 * @parent: Pointer to node to insert right child in
 * @value: Value to store new node
 * Return: Pointer to new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{

	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}
