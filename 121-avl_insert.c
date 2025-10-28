#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to insert
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			node = binary_tree_node(*tree, value);
			(*tree)->left = node;
		}
		else
			node = avl_insert(&((*tree)->left), value);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			node = binary_tree_node(*tree, value);
			(*tree)->right = node;
		}
		else
			node = avl_insert(&((*tree)->right), value);
	}
	else
		return (NULL);

	binary_tree_balance(*tree);
	return (node);
}
