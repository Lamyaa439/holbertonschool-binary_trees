#include "binary_trees.h"

/**
 * heap_size - measures the size of a binary tree
 * @root: pointer to the root node
 *
 * Return: size of tree
 */
size_t heap_size(const binary_tree_t *root)
{
	if (!root)
		return (0);
	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * heap_get_last - gets pointer to last node by index
 * @root: pointer to root
 * @index: index of node to find (1-based)
 *
 * Return: pointer to node or NULL
 */
heap_t *heap_get_last(heap_t *root, size_t index)
{
	return (binary_tree_get_node_by_index(root, index));
}

/**
 * swap_values - swaps 2 integers
 * @a: first int
 * @b: second int
 */
void swap_values(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * heapify_down - restores heap property going downward
 * @root: pointer to root
 */
void heapify_down(heap_t *root)
{
	heap_t *largest;
	int swapped;

	do {
		swapped = 0;
		largest = root;

		if (root->left && root->left->n > largest->n)
			largest = root->left;
		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest != root)
		{
			swap_values(&root->n, &largest->n);
			root = largest;
			swapped = 1;
		}
	} while (swapped);
}

/**
 * heap_extract - extracts the root value of a Max Binary Heap
 * @root: pointer to heap root pointer
 *
 * Return: value of removed node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	size_t size;
	heap_t *last, *parent;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = heap_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = heap_get_last(*root, size);
	(*root)->n = last->n;

	parent = last->parent;
	if (parent->right == last)
		parent->right = NULL;
	else
		parent->left = NULL;

	free(last);
	heapify_down(*root);

	return (value);
}
