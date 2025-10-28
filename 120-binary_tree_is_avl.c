#include "binary_trees.h"
#include <limits.h>

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: height of the tree
 */
static int height(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);
	left_h = height(tree->left);
	right_h = height(tree->right);
	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * is_bst - checks if a tree is a valid BST
 * @tree: pointer to the root node
 * @min: minimum value allowed
 * @max: maximum value allowed
 *
 * Return: 1 if valid BST, 0 otherwise
 */
static int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - recursive helper to check AVL properties
 * @tree: pointer to the root node
 *
 * Return: 1 if AVL, 0 otherwise
 */
static int is_avl_helper(const binary_tree_t *tree)
{
	int balance, left_h, right_h;

	if (tree == NULL)
		return (1);
	left_h = height(tree->left);
	right_h = height(tree->right);
	balance = left_h - right_h;

	if (balance < -1 || balance > 1)
		return (0);

	return (is_avl_helper(tree->left) && is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node
 *
 * Return: 1 if valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	return (is_avl_helper(tree));
}
