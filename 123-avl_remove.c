#include "binary_trees.h"

/**
 * avl_remove - removes node from AVL tree
 * @root: Pointer to root node of tree where node is to be removed
 * @value: Value to rmove in tree
 * Return: Pointer to new root node or 0 if unsuccessful
 */

avl_t *avl_remove(avl_t *root, int value)
{

	avl_t *current = node->right;

	while (current && current->left)
		current = current->left;
	return (current);
}

/**
 * update_height - Update node height
 * @node: node for which height is to be updated
 * Return: updated height.
 */

int update_height(avl_t *node)
{

	int leftheight;
	int rightheight;

	leftheight = node->left ? node->left->height : -1;
	rightheight = node->right ? node->right->height : -1;
	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * balance_factor - Determine balance factor
 * @node: Node to determine balance factor.
 * Return: balance factor
 */

int balance_factor(avl_t *node)
{

	int leftheight;
	int rightheight;

	leftheight = node->left ? node->left->height : -1;
	rightheight = node->right ? node->right->height : -1;
	return (leftheight - rightheight);
}

/**
 * rotate - Rotate
 * @node: Node to be rotated
 * Return: A rotated node
 */

avl_t *rotate(avl_t *node)
{

	int bf = balance_factor(node);

	if (bf > 1)
	{
		if (balance_factor(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (bf < -1)
	{
		if (balance_factor(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	return (node);
}

/**
 * avl_remove - Removes node containing value
 * @root: pointer to root of avle
 * @value: value to be removed
 * Return: Avl without the value
 */

avl_t *avl_remove(avl_t *root, int value)
{

	avl_t *temp;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			*temp = root->left ? root->left : root->right;
			free(root);
			return (temp);
		}
		*temp = find_successor(root);
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}
	root->height = update_height(root);
	return (rotate(root));
}
