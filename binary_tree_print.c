#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * print_t - Stores recursively level in a string array
 * @tree: Pointer to node to be print
 * @offset: Offset to print
 * @depth: Depth of node
 * @s: Buffer
 * Return: length of printed tree after process
 */

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{

	char f[6];
	int w, l, r, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	w = sprintf(f, "(%03d)", tree->n);
	l = print_t(tree->left, offset, depth + 1, s);
	r = print_t(tree->right, offset + l + w, depth + 1, s);
	for (i = 0; i < w; i++)
		s[depth][offset + l + i] = f[i];
	if (depth && is_left)
	{
		for (i = 0; i < w + r; i++)
			s[depth - 1][offset + l + w / 2 + i] = '-';
		s[depth - 1][offset + l + w / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < l + w; i++)
			s[depth - 1][offset - w / 2 + i] = '-';
		s[depth - 1][offset + l + w / 2] = '.';
	}
	return (l + w + r);
}

/**
 * _height - Measures height of binary tree
 * @tree: Pointer to node to measure height
 * Return: Height of tree beginning @node
 */

static size_t _height(const binary_tree_t *tree)
{

	size_t height_r;
	size_t height_l;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints binary tree
 *
 * @tree: Pointer to root node of tree to print
 */

void binary_tree_print(const binary_tree_t *tree)
{

	char **q;
	size_t height, l, k;

	if (!tree)
		return;
	height = _height(tree);
	q = malloc(sizeof(*q) * (height + 1));
	if (!q)
		return;
	for (l = 0; l < height + 1; l++)
	{
		q[l] = malloc(sizeof(**q) * 255);
		if (!q[l])
			return;
		memset(q[l], 32, 255);
	}
	print_t(tree, 0, 0, q);
	for (l = 0; l < height + 1; l++)
	{
		for (k = 254; k > 1; --k)
		{
			if (q[l][k] != ' ')
				break;
			q[l][k] = '\0';
		}
		printf("%s\n", q[l]);
		free(q[l]);
	}
	free(q);
}
