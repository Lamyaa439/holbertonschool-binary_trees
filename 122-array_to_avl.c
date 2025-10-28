#include "binary_trees.h"

/**
 * avl_insert_rec - helper to insert a value into an AVL tree
 * @tree: double pointer to the root node
 * @array: pointer to the array
 * @start: starting index
 * @end: ending index
 *
 * Return: pointer to the root node
 */
static avl_t *avl_insert_rec(avl_t **tree, int *array, int start, int end)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(NULL, array[mid]);
	if (node == NULL)
		return (NULL);

	node->left = avl_insert_rec(&node->left, array, start, mid - 1);
	if (node->left)
		node->left->parent = node;

	node->right = avl_insert_rec(&node->right, array, mid + 1, end);
	if (node->right)
		node->right->parent = node;

	if (*tree == NULL)
		*tree = node;

	return (node);
}

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	avl_insert_rec(&root, array, 0, (int)size - 1);
	return (root);
}
