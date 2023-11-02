#include "binary_trees.h"

/**
 * bst_insert - Inserts value in Binary Search Tree.
 * @tree: Double pointer to root node of BST to insert value.
 * @value: Value to store in node to insert
 * Return: Pointer to created node, or NULL.
 */

bst_t *bst_insert(bst_t **tree, int value)
{

	bst_t *current, *new_node;

	if (tree != NULL)
	{
		current = *tree;
		if (current == NULL)
		{
			new_node = binary_tree_node(current, value);
			if (new_node == NULL)
				return (NULL);
			return (*tree = new_node);
		}
		if (value < current->n)
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));
			new_node = binary_tree_node(current, value);
			if (new_node == NULL)
				return (NULL);
			return (current->left = new_node);
		}
		if (value > current->n)
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));
			new_node = binary_tree_node(current, value);
			if (new_node == NULL)
				return (NULL);
			return (current->right = new_node);
		}
	}
	return (NULL);
}
