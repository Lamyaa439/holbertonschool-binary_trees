#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node
 * @value: value to insert
 *
 * Return: pointer to created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *temp, *parent;
	int temp_val;
	size_t size, index, parent_index;

	if (!root)
		return (NULL);

	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);

	if (!*root) /* first node */
	{
		*root = new;
		return (new);
	}

	/* Find the place to insert: level-order index */
	size = binary_tree_size(*root);
	index = size + 1;

	/* Find parent by index rules: parent = i / 2 */
	parent_index = index / 2;
	parent = binary_tree_get_node_by_index(*root, parent_index);

	new->parent = parent;
	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	/* Bubble up (heapify up) */
	temp = new;
	while (temp->parent && temp->n > temp->parent->n)
	{
		temp_val = temp->n;
		temp->n = temp->parent->n;
		temp->parent->n = temp_val;
		temp = temp->parent;
	}

	return (new);
}
