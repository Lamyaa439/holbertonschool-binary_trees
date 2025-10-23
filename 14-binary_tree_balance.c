#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree:  is a pointer to the root node of the tree to measure the
 * balance factor
 *
 * Return: If tree is NULL, return 0
 *
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	int i;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		i = +0;
	if (tree->left != NULL && tree->right != NULL)
		i = +2;
	else if (tree->left != NULL || tree->right != NULL)
		i = -1;

	return (i);
}
