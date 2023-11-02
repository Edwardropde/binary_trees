#include "binary_trees.h"

/**
 * array_to_avl - Builds AVL tree from array.
 * @array: Pointer to first element of array to covert.
 * @size: Number of elements in array.
 * Return: Pointer to root node of created AVL, or NULL.
 */

avl_t *array_to_avl(int *array, size_t size)
{

	avl_t *new_avl = NULL;
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
			if (avl_insert(&new_avl, array[e]) == NULL)
				return (NULL);
		}
	}
	return (new_avl);
}
