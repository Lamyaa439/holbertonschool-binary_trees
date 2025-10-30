#include "binary_trees.h"

/**
 * heap_get_last - gets the last node in level-order of a heap
 * @root: pointer to root of heap
 * Return: pointer to last node, or NULL
 */
binary_tree_t *heap_get_last(binary_tree_t *root)
{
	binary_tree_t *queue[2048];
	binary_tree_t *node;
	size_t head = 0, tail = 0;

	if (!root)
		return (NULL);

	queue[tail++] = root;

	while (head < tail)
	{
		node = queue[head++];

		if (node->left)
			queue[tail++] = node->left;
		if (node->right)
			queue[tail++] = node->right;
	}

	return (node);
}
