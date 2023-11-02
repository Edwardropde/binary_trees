#include "binary_trees.h"

/**
 * array_to_bst - Builds binary search tree from array.
 * @array: Pointer to first element of array to be used.
 * @size: Number of elements in array.
 * Return: Pointer to root node of created BST, or NULL
 */

bst_t *array_to_bst(int *array, size_t size)
{

	bst_t *root_node = NULL;
	size_t e, k;

	if (array == NULL)
		return (NULL);
	for (e = 0; e < size; e++)
	{
		for (k = 0; k < e; k++)
		{
			if (array[k] == array[e])
				break;
		}
		if (k == e)
		{
			if (bst_insert(&root_node, array[e]) == NULL)
				return (NULL);
		}
	}
	return (root_node);
}
