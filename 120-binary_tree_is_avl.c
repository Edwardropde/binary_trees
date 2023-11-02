#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures height of binary tree
 * @tree: Pointer to root node of tree to measure height
 * Return: Height or NULL if otherwise
 */

size_t height(const binary_tree_t *tree)
{

	size_t left;
	size_t right;

	if (tree)
	{
		left = 0;
		right = 0;
		left = tree->left ? 1 + height(tree->left) : 1;
		right = tree->right ? 1 + height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if binary tree is valid AVL tree
 * @tree: Pointer to root node of tree to check
 * @lo: Value of smallest node
 * @hi: Value of largest node
 * Return: 1 if tree is valid AVL 0 if otherwise
 */

int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{

	size_t l, r, d;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		l = height(tree->left);
		r = height(tree->right);
		d = l > r ? l - r : r - l;
		if (d > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
				is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if binary tree is valied AVL treee
 * @tree: Pointer to root node of tree to check
 * Return: 1 if tree is valid, o if otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

