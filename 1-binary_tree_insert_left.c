#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: new node
 **/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(NULL, value);

	if (newNode == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		parent->left->parent = newNode;
		newNode->left = parent->left;
	}
	parent->left = newNode;
	newNode->parent = parent;

	return (newNode);
}
