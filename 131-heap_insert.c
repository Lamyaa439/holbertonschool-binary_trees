#include "binary_trees.h"

/**
 * swap_nodes - Swaps two nodes in the binary tree
 * @a: first node
 * @b: second node
 */
void swap_nodes(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
 * tree_size - Get size of binary tree
 * @tree: pointer to root
 * Return: size of tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_node_at_index - Get node position by index
 * @root: pointer to root
 * @index: index to find
 * Return: pointer to node or NULL
 */
heap_t *get_node_at_index(heap_t *root, size_t index)
{
	size_t parent_i;
	heap_t *parent;

	if (index == 0)
		return (root);

	parent_i = (index - 1) / 2;

	parent = get_node_at_index(root, parent_i);

	if (!parent)
		return (NULL);

	if (index == parent_i * 2 + 1)
		return (parent->left);
	else if (index == parent_i * 2 + 2)
		return (parent->right);

	return (NULL);
}

/**
 * heap_insert - Inserts value into Max Binary Heap
 * @root: double pointer to heap root
 * @value: value to insert
 * Return: pointer to inserted node, or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *parent;
	size_t size, index;

	if (!root)
		return (NULL);

	/* If empty tree, create root */
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = tree_size(*root);
	index = size;

	parent = get_node_at_index(*root, (index - 1) / 2);

	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);

	if (index % 2 == 1)
		parent->left = node;
	else
		parent->right = node;

	/* Heapify Up */
	while (node->parent && node->n > node->parent->n)
	{
		swap_nodes(node, node->parent);
		node = node->parent;
	}

	return (node);
}
