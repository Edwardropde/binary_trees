#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates binary tree.
 * @tree: Pointer to root node of tree to rotate.
 * Return: Pointer to new root node after left rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	new_root = tree->right;
	temp = new_root->left;
	new_root->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = new_root;
	new_root->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = new_root;
		else
			temp->right = new_root;
	}
	return (new_root);
}
