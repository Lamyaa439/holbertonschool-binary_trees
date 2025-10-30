#include "binary_trees.h"

/**
 * heap_get_last - gets the last node in level-order of a heap
 * @root: pointer to root of heap
 * Return: pointer to last node, or NULL
 */
heap_t *heap_get_last(heap_t *root)
{
	heap_t *queue[1024];
	size_t head = 0, tail = 0;

	if (!root)
		return (NULL);

	queue[tail++] = root;

	while (head < tail)
	{
		root = queue[head++];

		if (root->left)
			queue[tail++] = root->left;

		if (root->right)
			queue[tail++] = root->right;
	}

	return (root);
}
