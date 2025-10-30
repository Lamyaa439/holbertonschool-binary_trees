#include "binary_trees.h"

/**
 * bst_min_value - returns the node with the min value in a BST
 * @node: pointer to the BST node
 * Return: pointer to min node
 */
bst_t *bst_min_value(bst_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - remove a node in a BST
 * @root: pointer to the root node
 * @value: value to remove
 * Return: pointer to the new root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *min;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			min = root->right;
			if (min)
				min->parent = root->parent;
			free(root);
			return (min);
		}
		else if (!root->right)
		{
			min = root->left;
			if (min)
				min->parent = root->parent;
			free(root);
			return (min);
		}
		min = bst_min_value(root->right);
		root->n = min->n;
		root->right = bst_remove(root->right, min->n);
	}
	return (root);
}

/**
 * avl_remove - remove a node from an AVL tree
 * @root: pointer to root
 * @value: value to delete
 * Return: pointer to new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);

	root = (avl_t *)bst_remove(root, value);
	if (!root)
		return (NULL);

	/* rebalance */
	if (binary_tree_balance(root) > 1)
	{
		if (binary_tree_balance(root->left) >= 0)
			root = binary_tree_rotate_right(root);
		else
		{
			root->left = binary_tree_rotate_left(root->left);
			root = binary_tree_rotate_right(root);
		}
	}
	else if (binary_tree_balance(root) < -1)
	{
		if (binary_tree_balance(root->right) <= 0)
			root = binary_tree_rotate_left(root);
		else
		{
			root->right = binary_tree_rotate_right(root->right);
			root = binary_tree_rotate_left(root);
		}
	}
	return (root);
}
