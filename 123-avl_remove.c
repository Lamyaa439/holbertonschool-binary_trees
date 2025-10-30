#include "binary_trees.h"

/**
 * min_node - get node with minimum value in subtree
 * @node: pointer to root
 * Return: pointer to min node
 */
bst_t *min_node(bst_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - remove node from BST (fix parent)
 * @root: root pointer
 * @value: value to delete
 * Return: new root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *succ;

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
		if (!root->left || !root->right)
		{
			tmp = root->left ? root->left : root->right;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (tmp);
		}
		succ = min_node(root->right);
		root->n = succ->n;
		root->right = bst_remove(root->right, succ->n);
		if (root->right)
			root->right->parent = root;
	}
	return (root);
}

/**
 * rebalance - rebalance AVL node
 * @node: pointer to subtree root
 * Return: new root
 */
avl_t *rebalance(avl_t *node)
{
	int balance;

	if (!node)
		return (NULL);

	balance = binary_tree_balance(node);
	if (balance > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		node = binary_tree_rotate_right(node);
	}
	else if (balance < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		node = binary_tree_rotate_left(node);
	}
	return (node);
}

/**
 * avl_remove - remove value from AVL tree
 * @root: tree root
 * @value: value to delete
 * Return: new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);

	root = (avl_t *)bst_remove(root, value);
	if (!root)
		return (NULL);

	root = rebalance(root);
	if (root)
		root->parent = NULL;

	return (root);
}
