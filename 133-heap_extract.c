#include "binary_trees.h"

/* ---------- helpers ---------- */

/**
 * heap_get_last - return last node in level-order
 * @root: heap root
 * Return: pointer to last node, or NULL
 */
binary_tree_t *heap_get_last(binary_tree_t *root)
{
	binary_tree_t *queue[1024];
	size_t h = 0, t = 0, i = 0;

	if (!root)
		return (NULL);

	queue[t++] = root;
	while (h < t)
	{
		root = queue[h++];
		if (root->left)
			queue[t++] = root->left;
		if (root->right)
			queue[t++] = root->right;
		/* أمان بسيط لحجم الطابور */
		if (++i >= 1024)
			break;
	}
	return (root);
}

/**
 * swap_values - swap node values
 * @a: first node
 * @b: second node
 */
static void swap_values(heap_t *a, heap_t *b)
{
	int tmp = a->n;

	a->n = b->n;
	b->n = tmp;
}

/**
 * heapify_down - restore max-heap property downward
 * @root: start node
 */
static void heapify_down(heap_t *root)
{
	heap_t *largest;

	while (root)
	{
		largest = root;
		if (root->left && root->left->n > largest->n)
			largest = root->left;
		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		swap_values(root, largest);
		root = largest;
	}
}

/* ---------- main API ---------- */

/**
 * heap_extract - extract max from a Max Binary Heap
 * @root: address of heap root pointer
 * Return: removed value, or 0 on failure/empty
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int val;

	if (!root || !*root)
		return (0);

	val = (*root)->n;
	last = (heap_t *)heap_get_last(*root);

	if (last == *root)
	{
		free(*root);
		*root = NULL;
		return (val);
	}

	/* انقل قيمة آخر عقدة للقمة ثم احذف العقدة الأخيرة */
	(*root)->n = last->n;
	if (last->parent->right == last)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;
	free(last);

	heapify_down(*root);
	return (val);
}
