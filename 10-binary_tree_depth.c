#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Node from which to measure backwards, starting at 0
 *
 * Return: Levels from root, or 0 if `tree` is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;
