#include "binary_trees.h"

/**
 * heapify_down - restores Max Heap property after extraction
 * @root: pointer to root of heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root, *left, *right;
	int temp;

	if (!root)
		return;

	left = root->left;
	right = root->right;

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * heap_extract - extracts the root value of a Max Binary Heap
 * @root: double pointer to heap root
 * Return: extracted value, or 0 on failure/empty heap
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int val;

	if (!root || !*root)
		return (0);

	val = (*root)->n;
	last = heap_get_last(*root);

	if (last == *root) /* only one node in heap */
	{
		free(*root);
		*root = NULL;
		return (val);
	}

	/* move last node value to root */
	(*root)->n = last->n;

	/* detach last node */
	if (last->parent->right == last)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;

	free(last);

	/* restore heap */
	heapify_down(*root);

	return (val);
}
