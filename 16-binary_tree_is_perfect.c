#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Determines if node is leaf or binary tree
 * @node: Pointer to node to be checked
 * Return: 1 if node is a leaf o if otherwise
 */

unsigned char is_leaf(const binary_tree_t *node)
{

	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth: Returns depth of a specific node in binary tree
 * @tree: Pointer to node to measure depth
 * Return: Node depth
 */

size_t depth(const binary_tree_t *tree)
{

	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Return leaf of binary tree
 * @tree: Pointer to root node of tree to find leaf in
 * Return: Pointer to first got leaf
 */

const binary_tree_t *get_leaf(const binary_tree_t *tree)
{

	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - determines if binary s perfect recursively
 * @tree: pointer to root node of tree to check
 * @leaf_depth: Depth of a single leaf in binary tree
 * @level: Level of current node
 * Return: 1 if tree is perfect otherwise 0
 */

int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{

	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect  - Checks if binary tree is perfect
 * @tree: Pointer to root node of tree to check
 * Return: 1 if tree is perfect otherwise 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
