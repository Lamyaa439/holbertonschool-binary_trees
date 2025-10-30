#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node
 * @index: Index of the current node
 * @size: Number of nodes in the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (binary_tree_is_complete(tree->left, 2 * index + 1, size) &&
		binary_tree_is_complete(tree->right, 2 * index + 2, size));
}

/**
 * count_nodes - Counts nodes in a binary tree
 * @tree: Pointer to root node
 *
 * Return: Number of nodes
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * check_max_heap - Checks heap property recursively
 * @tree: Pointer to root node
 *
 * Return: 1 if max-heap, 0 otherwise
 */
int check_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && tree->n < tree->left->n)
		return (0);

	if (tree->right && tree->n < tree->right->n)
		return (0);

	return (check_max_heap(tree->left) && check_max_heap(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node
 *
 * Return: 1 if valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = count_nodes(tree);

	if (!binary_tree_is_complete(tree, 0, size))
		return (0);

	return (check_max_heap(tree));
}
