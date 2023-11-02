#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Measures Binary tree height
 * @tree: Pointer to root node of tree to measure height
 * Return: Height or 0 if otherwise
 */

size_t height(const binary_tree_t *tree)
{

	size_t left, right;

	if (tree != NULL)
	{
		left = 0;
		right = 0;
		left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}

/**
 * balance - Measures binary tree balance
 * @tree: Pointer to root node of tree to be measured
 * Return: 1 for Balance factor or 0 if otherwise
 */

int balance(const binary_tree_t *tree)
{

	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Recursively inserts value into AVL tree
 * @tree: Double pointer to root node of AVL tree to insert
 * @parent: Parent node of current working node
 * @new: Double pointer to store created node
 * @value: Value to insert in AVL tree
 * Return: Pointer to new root after operation. 0 if otherwise
 */

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{

	int balancer;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));
	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);
	balancer = balance(*tree);
	if (balancer > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balancer < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balancer > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balancer < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts value into AVL tree.
 * @tree: Double pointer to root node of AVL tree to insert into.
 * @value: Value to insert into the AVL tree.
 * Return: Pointer to inserted node or NULL if otherwise
 */

avl_t *avl_insert(avl_t **tree, int value)
{

	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new_node, value);
	return (new_node);
}
