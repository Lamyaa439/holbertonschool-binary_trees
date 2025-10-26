#include "binary_trees.h"
/**
 * tree_stats - function that computes some statistics about a binary tree.
 * @tree: pointer to the root node of the tree to check.
 * @n: accumulated height of the current path in the tree.
 * @leaves: pointer to the tree's leaf count value.
 * @height: pointer to the trees max height value.
 * Return: void.
 **/
void tree_stats(const binary_tree_t *tree, size_t n, size_t *leaves,
size_t *height)
{
	if (tree != NULL)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			if (leaves != NULL)
				(*leaves)++;
			if (height != NULL && n > *height)
				*height = n;
		}
		else
		{
			tree_stats(tree->left, n + 1, leaves, height);
			tree_stats(tree->right, n + 1, leaves, height);
		}
	}
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves_count = 0, tree_height = 0;

	tree_stats(tree, 0, &leaves_count, &tree_height);
	return ((int)leaves_count == (1 << tree_height) ? 1 : 0);


}
