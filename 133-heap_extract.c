#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int heapify_and_extract(heap_t **root);
heap_t *find_last_node(heap_t *root);

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 * Return: Value stored in the root node, or 0 on failure
 */

int heap_extract(heap_t **root)
{

	int value;

	if (root == NULL || *root == NULL)
		return (0);
	value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	value = heapify_and_extract(root);
	return (value);
}

/**
 * heapify_and_extract - replaces the root node with the last level-order node
 * @root: Double pointer to the root node of heap
 * Return: Value stored in the original root node
 */

int heapify_and_extract(heap_t **root)
{

	heap_t *node, *replace;
	heap_t *largest, *left, *right;
	int value;

	value = (*root)->n;
	replace = find_last_node(*root);
	if (replace->parent->left == replace)
		replace->parent->left = NULL;
	else
		replace->parent->right = NULL;
	(*root)->n = replace->n;
	free(replace);
	node = *root;
	while (1)
	{
		largest = node;
		left = node->left;
		right = node->right;
		if (left && left->n > largest->n)
			largest = left;
		if (right && right->n > largest->n)
			largest = right;
		if (largest == node)
			break;
		value = node->n;
		node->n = largest->n;
		largest->n = value;
		node = largest;
	}
	return (value);
}

/**
 * find_last_node - finds the last level-order node in the heap
 * @root: Pointer to the root node of heap
 * Return: Pointer to the last node
 */

heap_t *find_last_node(heap_t *root)
{

	heap_t *node = root;

	while (node->left || node->right)
	{
		if (node->right)
			node = node->right;
		else
			node = node->left;
	}
	return (node);
}
