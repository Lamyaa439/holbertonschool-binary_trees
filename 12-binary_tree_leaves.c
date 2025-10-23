#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: is a pointer to the root node of the tree to count
 * Return: If tree is NULL, the function must return 0
 **/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count_left, count_right;

	count_left = count_right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	count_left = binary_tree_leaves(tree->left);
	count_right = binary_tree_leaves(tree->right);

	return (count_left + count_right);
}
