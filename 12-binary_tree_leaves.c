#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: is a pointer to the root node of the tree to count
 * the number of leaves
 * Return: If tree is NULL, the function must return 0
 * A NULL pointer is not a leaf
 **/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count;

	count = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		count += 1;
	if (tree->right != NULL)
		count += 1;

	return (count);
}
