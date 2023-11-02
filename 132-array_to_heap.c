#include "binary_trees.h"

/**
 * array_to_heap - builds max binary heap from array
 * @array: Pointer to first element of array to be converted
 * @size: Number of elements in array
 * Return: Pointer to root node of created binary heap, NULL if otherwise
 */

heap_t *array_to_heap(int *array, size_t size)
{

	unsigned int j;
	heap_t *p = NULL;

	for (j = 0; j < size; j++)
		heap_insert(&p, array[j]);
	return (p);
}
