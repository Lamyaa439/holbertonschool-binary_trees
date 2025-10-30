#include "binary_trees.h"

/**
 * bst_remove - removes a node from a BST tree
 * @root: pointer to root
 * @value: value to remove
 * Return: pointer to new root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

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
			tmp = root->right;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (tmp);
		}
		else
		{
			tmp = root->right;
			while (tmp->left)
				tmp = tmp->left;
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}
	return (root);
}

/**
 * avl_remove - removes node from an AVL tree and balances it
 * @root: pointer to tree root
 * @value: value to remove
 * Return: pointer to new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);

	root = (avl_t *)bst_remove(root, value);

	if (!root)
		return (NULL);

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
