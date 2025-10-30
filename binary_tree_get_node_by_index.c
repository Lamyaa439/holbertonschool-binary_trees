#include "binary_trees.h"

/**
 * binary_tree_get_node_by_index - gets node by BFS index (like heap)
 * @root: root pointer
 * @index: index (1-based)
 * Return: node pointer or NULL
 */
binary_tree_t *binary_tree_get_node_by_index(binary_tree_t *root, size_t index)
{
	binary_tree_t *queue[1024];
	size_t head = 0, tail = 0, i = 1;

	if (!root || index == 0)
		return (NULL);

	queue[tail++] = root;

	while (head < tail)
	{
		binary_tree_t *node = queue[head++];

		if (i == index)
			return (node);

		if (node->left)
			queue[tail++] = node->left;
		if (node->right)
			queue[tail++] = node->right;

		i++;
	}

	return (NULL);
}
