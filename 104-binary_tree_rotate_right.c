#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates binary tree.
 * @tree: Pointer to root node of tree to rotate.
 * Return: Pointer to new root node after right rotation.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{

	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	new_root = tree->left;
	temp = new_root->right;
	new_root->right = tree;
	tree->left = temp;
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
