#include "binary_trees.h"

/**
 * heap_get_last - gets the last node in level-order of a heap
 * @root: pointer to root of heap
 * Return: pointer to last node or NULL
 */
binary_tree_t *heap_get_last(binary_tree_t *root)
{
	binary_tree_t *queue[1024];
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

/**
 * heapify_down - restores Max Heap property after extraction
 * @root: pointer to root node
 */
void heapify_down(binary_tree_t *root)
{
	binary_tree_t *max;
	int temp;

	while (root)
	{
		max = root;

		if (root->left && root->left->n > max->n)
			max = root->left;
		if (root->right && root->right->n > max->n)
			max = root->right;

		if (max == root)
			return;

		temp = root->n;
		root->n = max->n;
		max->n = temp;

		root = max;
	}
}

/**
 * heap_extract - extracts the root value of a Max Binary Heap
 * @root: double pointer to root node
 * Return: value of extracted node or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *parent;
	int value;

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

	(*root)->n = last->n;
	parent = last->parent;

	if (parent->left == last)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last);
	heapify_down(*root);

	return (value);
}
