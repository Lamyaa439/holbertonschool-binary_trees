#include "binary_trees.h"

/**
 * build_avl - builds an AVL tree from a sorted array
 * @array: pointer to first element of array
 * @start: start index
 * @end: end index
 * @parent: parent node
 *
 * Return: pointer to created AVL subtree root
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = build_avl(array, start, mid - 1, root);
	root->right = build_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to first array element
 * @size: size of the array
 *
 * Return: pointer to root of AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl(array, 0, (int)size - 1, NULL));
}
