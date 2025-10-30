#include "binary_trees.h"

/**
 * heap_get_last - gets last node in heap using BFS index rule
 * @root: pointer to root node
 * Return: pointer to last node
 */
binary_tree_t *heap_get_last(binary_tree_t *root)
{
    size_t size;
    
    if (!root)
        return (NULL);

    size = binary_tree_size(root);
    return (binary_tree_get_node_by_index(root, size));
}
