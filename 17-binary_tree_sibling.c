#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_sibling -  finds the sibling of a node
 * @node: is a pointer to the node to find the sibling
 *
 * Return: return a pointer to the sibling node
 * If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
 **/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *left = NULL;
	binary_tree_t *right = NULL;

	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left)
}
