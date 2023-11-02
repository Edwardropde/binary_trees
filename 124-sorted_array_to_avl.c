#include "binary_trees.h"

void sata_helper(avl_t **root, int *array, size_t lo, size_t hi);

/**
 * sorted_array_to_avl - creates AVL tree from array
 * @array: Pointer to first element of array to convert
 * @size: Number of elements in array
 * Return: Pointer to root node of created AVL tree. NULL if otherwise
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{

	avl_t *t = NULL;
	size_t mid;

	if (!array)
		return (NULL);
	mid = (size - 1) / 2;
	t = binary_tree_node(NULL, array[mid]);
	sata_helper(&t, array, -1, mid);
	sata_helper(&t, array, mid, size);
	return (t);
}

/**
 * sata_helper - helper to builds AVL tree from array
 * @root: Double pointer to root node
 * @array: Pointer to first element of array to convert
 * @lo: lower bound index
 * @hi: upper bound index
 */

void sata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{

	avl_t *n = NULL;
	size_t mid;

	if (hi - lo > 1)
	{
		mid = (hi - lo) / 2 + lo;
		n = binary_tree_node(*root, array[mid]);
		if (array[mid] > (*root)->n)
			(*root)->right = n;
		else if (array[mid] < (*root)->n)
			(*root)->left = n;
		sata_helper(&n, array, lo, mid);
		sata_helper(&n, array, mid, hi);
	}
}
