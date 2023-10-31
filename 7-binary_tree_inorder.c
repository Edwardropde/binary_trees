#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through binary tree using in-order traversal
 * @tree: Pointer to root node of tree to traverse
 * @func: Pointer to function to call for every node
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{

	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
