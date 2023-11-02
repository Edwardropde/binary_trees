#include "binary_trees.h"

void heapify(heap_t *node);

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */

void swap(int *a, int *b)
{

	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * get_last_node - Get the last node in the heap
 * @root: Pointer to the root node of the heap
 */

heap_t *get_last_node(heap_t *root)
{

	while (root->left || root->right)
	{
		if (root->right)
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to arr of int
 * @heap: Pointer to the root node of the heap
 * @size: Pointer to store the size of the array
 * Return: Pointer to the sorted array
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{

	int *sorted_array;
	size_t n, i;
	heap_t *last_node;

	if (!heap || !size)
		return (NULL);
	n = 0;
	last_node = get_last_node(heap);
	n = binary_tree_size(heap);
	sorted_array = malloc(sizeof(int) * n);
	if (!sorted_array)
		return (NULL);
	for (i = 0; i < n; i++)
	{
		sorted_array[i] = heap->n;
		if (i < n - 1)
		{
			swap(&(heap->n), &(last_node->n));
			if (last_node->parent->left == last_node)
				last_node->parent->left = NULL;
			else
				last_node->parent->right = NULL;
			free(last_node);
			heapify(heap);
			last_node = get_last_node(heap);
		}
	}
	*size = n;
	return (sorted_array);
}
