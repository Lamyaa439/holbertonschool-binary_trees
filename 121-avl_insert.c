#include "binary_trees.h"

/**
 * rebalance_left - rebalance after inserting in left subtree
 * @tree: double pointer to root
 * @value: inserted value
 */
void rebalance_left(avl_t **tree, int value)
{
	if (value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		(*tree)->left->parent = *tree;
		*tree = binary_tree_rotate_right(*tree);
	}
}

/**
 * rebalance_right - rebalance after inserting in right subtree
 * @tree: double pointer to root
 * @value: inserted value
 */
void rebalance_right(avl_t **tree, int value)
{
	if (value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		(*tree)->right->parent = *tree;
		*tree = binary_tree_rotate_left(*tree);
	}
}

/**
 * avl_insert_recursive - inserts a value into an AVL tree recursively
 * @tree: double pointer to AVL tree root
 * @value: value to insert
 * Return: pointer to created node, or NULL
 */
binary_tree_t *avl_insert_recursive(avl_t **tree, int value)
{
	binary_tree_t *node;

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	if (value < (*tree)->n)
	{
		node = avl_insert_recursive(&((*tree)->left), value);
		if (!node)
			return (NULL);
		(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		node = avl_insert_recursive(&((*tree)->right), value);
		if (!node)
			return (NULL);
		(*tree)->right->parent = *tree;
	}
	else
		return (NULL);

	if (binary_tree_balance(*tree) > 1)
		rebalance_left(tree, value);
	else if (binary_tree_balance(*tree) < -1)
		rebalance_right(tree, value);

	return (node);
}

/**
 * avl_insert - inserts value in an AVL tree
 * @tree: pointer to root pointer
 * @value: value to insert
 * Return: pointer to created node, or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	return ((avl_t *)avl_insert_recursive(tree, value));
}
