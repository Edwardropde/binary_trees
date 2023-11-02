#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
int btih_helper(const binary_tree_t *tree);
int btic_helper(const binary_tree_t *tree, size_t index, size_t size);

/**
 * binary_tree_is_heap - checks if binary tree is valid max binary heap
 * @tree: Pointer to root node of tree
 * Return: 1 if tree is valid max binary heap, 0 if otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	return (btih_helper(tree));
}

/**
 * btih_helper - checks if binary is valid max binary heap
 * @tree: Pointer to root node
 * Return: 1 if tree is valid Max Binary Heap, 0 if otherwise
 */

int btih_helper(const binary_tree_t *tree)
{

	if (!tree)
		return (1);
	if (!binary_tree_is_complete(tree))
		return (0);
	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);
	return (btih_helper(tree->left) &&
			btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: Pointer to root node
 * Return: 1 if tree is complete, 0 if otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{

	int s;

	if (!tree)
		return (0);
	s = binary_tree_size(tree);
	return (btic_helper(tree, 0, s));
}

/**
 * btic_helper - checks if binary tree is complete
 * @tree: Pointer to root node
 * @index: Node index to check
 * @size: Number of nodes in tree
 * Return: 1 if tree is complete, 0 if otherwise
 */

int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{

	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (btic_helper(tree->left, 2 * index + 1, size) &&
			btic_helper(tree->right, 2 * index + 2, size));
}
