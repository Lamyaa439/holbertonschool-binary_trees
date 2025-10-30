#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array
 * @heap: pointer to heap root
 * @size: pointer to store the array size
 * Return: pointer to sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t count = 0, i = 0;
	heap_t *tmp = heap;

	if (!heap || !size)
		return (NULL);

	/* count nodes to allocate array */
	while (tmp)
	{
		tmp = tmp->right;
		count++;
	}

	array = malloc(sizeof(int) * count);
	if (!array)
		return (NULL);

	for (i = 0; i < count; i++)
		array[i] = heap_extract(&heap);

	/* reverse array to make it ascending order */
	for (i = 0; i < count / 2; i++)
	{
		int tmp_val = array[i];

		array[i] = array[count - 1 - i];
		array[count - 1 - i] = tmp_val;
	}

	*size = count;
	return (array);
}
