#include "binary_trees.h"

/**
 * tree_size - Get size of binary tree
 * @tree: pointer to root
 * Return: size of tree, 0 if NULL
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * find_parent - Find parent by BFS index logic
 * @root: pointer to heap root
 * @idx: parent index
 * Return: parent node pointer
 */
static heap_t *find_parent(heap_t *root, size_t idx)
{
	size_t high = 1;

	while ((high << 1) <= idx)
		high <<= 1;

	high >>= 1;

	while (high)
	{
		if (idx & high)
			root = root->right;
		else
			root = root->left;
		high >>= 1;
	}

	return (root);
}

/**
 * heap_bubble_up - Restore heap by swapping values up
 * @node: pointer to newly inserted node
 * Return: final position of node
 */
static heap_t *heap_bubble_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Insert value in Max Binary Heap
 * @root: double pointer to heap root
 * @value: value to insert
 * Return: pointer to inserted node (final pos)
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size, pidx;
	heap_t *parent, *node;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = tree_size(*root) + 1;
	pidx = size / 2;
	parent = find_parent(*root, pidx);

	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);

	if (!parent->left)
		parent->left = node;
	else
		parent->right = node;

	return (heap_bubble_up(node));
}
