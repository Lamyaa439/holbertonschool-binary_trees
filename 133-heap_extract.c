#include "binary_trees.h"

/**
 * heap_extract - Extracts the root value of a Max Binary Heap
 * @root: Double pointer to the root of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last, *node;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	last = heap_get_last(*root);

	if (last == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	node = *root;
	node->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);

	heapify(node);

	return (value);
}
