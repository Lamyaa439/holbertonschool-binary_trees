#include "binary_trees.h"

/**
 * min_node - return the node with the minimum value in a subtree
 * @root: pointer to subtree root
 * Return: pointer to minimum node
 */
static avl_t *min_node(avl_t *root)
{
	while (root && root->left)
		root = root->left;
	return (root);
}

/**
 * rebalance - rebalance an AVL subtree
 * @root: pointer to subtree root
 * Return: pointer to new root after rotations
 */
static avl_t *rebalance(avl_t *root)
{
	int bal;

	if (!root)
		return (NULL);

	bal = binary_tree_balance(root);

	if (bal > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		root = binary_tree_rotate_right(root);
	}
	else if (bal < -1)
	{
		if (binary_tree_balance(root->right) > 0)
			root->right = binary_tree_rotate_right(root->right);
		root = binary_tree_rotate_left(root);
	}
	return (root);
}

/**
 * delete_node - delete node and return child pointer for replace
 * @root: node to delete
 * Return: replacement subtree root
 */
static avl_t *delete_node(avl_t *root)
{
	avl_t *child;

	child = root->left ? root->left : root->right;
	if (child)
		child->parent = root->parent;

	free(root);
	return (child);
}

/**
 * avl_remove - remove a value from an AVL tree
 * @root: pointer to root node of AVL tree
 * @value: value to delete
 * Return: pointer to new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *succ;

	if (!root)
		return (NULL);

	if (value < root->n)
	{
		root->left = avl_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = avl_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
	{
		if (!root->left || !root->right)
			return (delete_node(root));

		succ = min_node(root->right);
		root->n = succ->n;

		root->right = avl_remove(root->right, succ->n);
		if (root->right)
			root->right->parent = root;
	}

	root = rebalance(root);
	return (root);
}
