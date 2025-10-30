#include "binary_trees.h"

/**
 * swap_nodes - swap values between two nodes
 * @a: node a
 * @b: node b
 */
void swap_nodes(heap_t *a, heap_t *b)
{
	int tmp;

	tmp = a->n;
	a->n = b->n;
	b->n = tmp;
}

/**
 * tree_size - measure size of binary tree
 * @tree: pointer to tree root
 * Return: size
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_node_at_index - return node at given index
 * @root: tree root
 * @index: node index
 * Return: pointer to node or NULL
 */
heap_t *get_node_at_index(heap_t *root, size_t index)
{
	size_t parent_idx;
	heap_t *parent;

	if (index == 0)
		return (root);

	parent_idx = (index - 1) / 2;
	parent = get_node_at_index(root, parent_idx);

	if (!parent)
		return (NULL);

	if (index == parent_idx * 2 + 1)
		return (parent->left);

	if (index == parent_idx * 2 + 2)
		return (parent->right);

	return (NULL);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to heap root
 * @value: value to insert
 * Return: pointer to created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *parent;
	size_t size, idx;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = tree_size(*root);
	idx = size;

	parent = get_node_at_index(*root, (idx - 1) / 2);
	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);

	if (idx % 2 == 1)
		parent->left = node;
	else
		parent->right = node;

	while (node->parent && node->n > node->parent->n)
	{
		swap_nodes(node, node->parent);
		node = node->parent;
	}

	return (node);
}
