#include "binary_trees.h"

/**
 * min_value_node - finds the node with minimum value in a subtree
 * @node: pointer to the subtree root
 *
 * Return: pointer to the node with minimum value
 */
bst_t *min_value_node(bst_t *node)
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
	bst_t *temp, *successor;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}

		successor = min_value_node(root->right);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}
