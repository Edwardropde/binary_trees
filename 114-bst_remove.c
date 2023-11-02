#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Returns min val of binary search tree
 * @root: Pointer to root node of BST to search
 * Return: Min Val in tree
 */

bst_t *inorder_successor(bst_t *root)
{

	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Delete node in binary search tree
 * @root: Pointer to BST root node
 * @node: Pointer to node to be deleted
 * Return: Pointer to new root node after operation.
 */

bst_t *bst_delete(bst_t *root, bst_t *node)
{

	bst_t *pop = node->parent, *child = NULL;

	if (node->left == NULL)
	{
		if (pop != NULL && pop->left == node)
			pop->left = node->right;
		else if (pop != NULL)
			pop->right = node->right;
		if (node->right != NULL)
			node->right->parent = pop;
		free(node);
		return (pop == NULL ? node->right : root);
	}
	if (node->right == NULL)
	{
		if (pop != NULL && pop->left == node)
			pop->left = node->left;
		else if (pop != NULL)
			pop->right = node->left;
		if (node->left != NULL)
			node->left->parent = pop;
		free(node);
		return (pop == NULL ? node->left : root);
	}
	child = inorder_successor(node->right);
	node->n = child->n;
	return (bst_delete(root, child));
}

/**
 * bst_remove_recursive- Recursively deletes node from binary search tree
 * @root: Pointer to root node of BST to remove node from
 * @node: Pointer to current node
 * @value: Value to remove.
 * Return: Pointer to root node after operation.
 */

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{

	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes node from BST
 * @root: Pointer to root node of BST to remove node from
 * @value: Value to remove
 * Return: Pointer to new root nde after operation.
 */

bst_t *bst_remove(bst_t *root, int value)
{

	return (bst_remove_recursive(root, root, value));
}
