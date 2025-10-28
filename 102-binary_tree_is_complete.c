#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    const binary_tree_t **queue;
    size_t front = 0, rear = 0;
    int found_null = 0;

    if (tree == NULL)
        return (0);

    queue = malloc(sizeof(*queue) * 1024);
    if (!queue)
        return (0);

    queue[rear++] = tree;

    while (front < rear)
    {
        const binary_tree_t *node = queue[front++];

        if (node)
        {
            if (found_null)
            {
                free(queue);
                return (0); 
            }

            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
        else
        {
            found_null = 1; 
        }
    }

    free(queue);
    return (1);
}
