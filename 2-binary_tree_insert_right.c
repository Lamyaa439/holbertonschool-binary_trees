#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 * Return: new node
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(NULL, value);

	if (newNode == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		parent->right->parent = newNode;
		newNode->right = parent->right;
	}
	parent->right = newNode;
	newNode->parent = parent;

	return (newNode);
}
