#include "binary_trees.h"
/**
 * node_height - function that computes height of a binary tree's node.
 * @tree: pointer to the root node of the tree to measure the height.
 * @n: accumulated height
 * @height: pointer to the max height in the node's tree.
 * Return: void
 **/
void node_height(const binary_tree_t *tree, int n, int *height)
{
	if (tree != NULL)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			if (n > *height)
				*height = n;
		}
		else
		{
			node_height(tree->left, n + 1, height);
			node_height(tree->right, n + 1, height);
		}
	}
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree:  is a pointer to the root node of the tree to measure
 * Return: If tree is NULL, return 0
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0, left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	node_height(tree->left, 1, &left_height);
	node_height(tree->right, 1, &right_height);
	balance_factor = left_height - right_height;
	return (balance_factor);
}
