#include "binary_trees.h"

/**
 * min_node - find the smallest value node in a subtree
 * @root: pointer to the subtree root
 * Return: pointer to the minimum node
 */
avl_t *min_node(avl_t *root)
{
	while (root && root->left)
		root = root->left;
	return (root);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root of the AVL tree
 * @value: value to remove
 * Return: pointer to new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tmp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n) /* search left */
		root->left = avl_remove(root->left, value);

	else if (value > root->n) /* search right */
		root->right = avl_remove(root->right, value);

	else /* node found */
	{
		/* node with 0 or 1 child */
		if (!root->left || !root->right)
		{
			tmp = root->left ? root->left : root->right;

			if (tmp)
				tmp->parent = root->parent;

			free(root);
			return (tmp);
		}

		/* node with 2 children → get inorder successor */
		tmp = min_node(root->right);
		root->n = tmp->n;
		root->right = avl_remove(root->right, tmp->n);
	}

	/* ----- Rebalance ----- */
	if (!root)
		return (NULL);

	root->parent = NULL;
	int balance = binary_tree_balance(root);

	/* Left heavy */
	if (balance > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	/* Right heavy */
	if (balance < -1)
	{
		if (binary_tree_balance(root->right) > 0)
			root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
