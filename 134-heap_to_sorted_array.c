#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array
 * @heap: pointer to root node of the heap
 * @size: address to store size of array
 *
 * Return: pointer to sorted array (descending order), or NULL
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t i = 0, heap_size;
	int *array;

	if (!heap || !size)
		return (NULL);

	heap_size = binary_tree_size(heap);
	*size = heap_size;

	array = malloc(sizeof(int) * heap_size);
	if (!array)
		return (NULL);

	while (heap)
	{
		array[i++] = heap_extract(&heap);
	}

	return (array);
}
