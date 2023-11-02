#include "binary_trees.h"

void heapify(heap_t *node);

/**
 * find_parent - finds the parent for a new node
 * @root: pointer to the root of the tree
 * Return: pointer to the parent node
 */

heap_t *find_parent(heap_t *root)
{

	if (root == NULL)
		return (NULL);
	if (root->left == NULL || root->right == NULL)
		return (root);
	if (binary_tree_is_perfect(root->left) &&
			!binary_tree_is_perfect(root->right))
		return (find_parent(root->left));
	else
		return (find_parent(root->right));
}

/**
 * heap_insert - inserts value in max binary heap
 * @root: Double pointer to root node of heap
 * @value: Value to put in node to be inserted
 * Return: Pointer to created node, NULL if otherwise
 */

heap_t *heap_insert(heap_t **root, int value)
{

	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}
	parent = find_parent(*root);
	new_node->parent = parent;
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;
	heapify(new_node);
	return (new_node);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 if perfect, 0 otherwise
 */

int binary_tree_is_perfect(const heap_t *tree)
{

	int left_height = 0, right_height = 0;
	const binary_tree_t *left = tree, *right = tree;

	while (left)
	{
		left_height++;
		left = left->left;
	}
	while (right)
	{
		right_height++;
		right = right->right;
	}
	return (left_height == right_height);
}

/**
 * heapify - maintain the Max Heap property
 * @node: pointer to the new node to heapify
 */

void heapify(heap_t *node)
{

	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}
