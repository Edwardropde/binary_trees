#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insert node as left child of other binary tree
 * @parent: Pointer to node to insert left child in
 * @value: Value to store in new node
 * Return: If left-child exists, new node replaces it and old left
 * child is set as left child of new node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
