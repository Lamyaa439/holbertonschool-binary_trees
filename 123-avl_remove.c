#include "binary_trees.h"

/**
 * bst_min_value - returns the node with the minimum value in a BST
 * @node: pointer to a BST node
 * Return: pointer to the min node
 */
static bst_t *bst_min_value(bst_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - removes a value from a BST (fixes parent pointers)
 * @root: pointer to root of BST
 * @value: value to remove
 * Return: pointer to new root
 */
static bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
	{
		bst_t *child, *succ;

		/* node with at most one child */
		if (!root->left || !root->right)
		{
			child = root->left ? root->left : root->right;
			if (child)
				child->parent = root->parent;
			free(root);
			return (child);
		}

		/* node with two children -> replace with inorder successor */
		succ = bst_min_value(root->right);
		root->n = succ->n;
		root->right = bst_remove(root->right, succ->n);
		if (root->right)
			root->right->parent = root;
	}
	return (root);
}

/**
 * avl_rebalance - rebalances an AVL tree at given root
 * @root: pointer to current root
 * Return: pointer to new root after rotations (may be same)
 */
static avl_t *avl_rebalance(avl_t *root)
{
	int bal;

	if (!root)
		return (NULL);

	bal = binary_tree_balance(root);

	/* Left heavy */
	if (bal > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		root = binary_tree_rotate_right(root);
	}
	/* Right heavy */
	else if (bal < -1)
	{
		if (binary_tree_balance(root->right) > 0)
			root->right = binary_tree_rotate_right(root->right);
		root = binary_tree_rotate_left(root);
	}

	/* ensure root->parent is consistent at top-level use */
	return (root);
}

/**
 * avl_remove - removes a value from an AVL tree and rebalances it
 * @root: pointer to root of AVL tree
 * @value: value to remove
 * Return: pointer to new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);

	/* delete from BST while maintaining parent pointers */
	root = (avl_t *)bst_remove(root, value);

	/* if tree became empty */
	if (!root)
		return (NULL);

	/* rebalance at this root */
	root = avl_rebalance(root);

	/* top-level root should have NULL parent */
	if (root)
		root->parent = NULL;

	return (root);
}
