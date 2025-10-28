#include "binary_trees.h"
#include <stdlib.h>

/**
 * min_value_node - finds the node with minimum value in a subtree
 * @node: pointer to the subtree root
 *
 * Return: pointer to the node with minimum value
 */
static bst_t *min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
		current = current->left;

	return (current);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *successor;

	if (root == NULL)
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
		if (root->left == NULL)
		{
			tmp = root->right;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (tmp);
		}

		successor = min_value_node(root->right);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
		if (root->right)
			root->right->parent = root;
	}

	return (root);
}
