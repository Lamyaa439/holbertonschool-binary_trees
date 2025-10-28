#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	size_t front = 0, rear = 0, size = 0;

	if (tree == NULL || func == NULL)
		return;

	size = 1024;
	queue = malloc(sizeof(binary_tree_t *) * size);
	if (queue == NULL)
		return;

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *node = queue[front++];

		func(node->n);

		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;

		if (rear >= size)
		{
			size *= 2;
			queue = realloc((void *) queue,
					sizeof(binary_tree_t *) * size);
			if (queue == NULL)
				return;
		}
	}

	free((void *) queue);
}
