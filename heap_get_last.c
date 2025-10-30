#include "binary_trees.h"

/**
 * heap_get_last - gets pointer to last node in heap by index
 * @root: pointer to root
 * @index: index (1-based)
 *
 * Return: pointer to node or NULL
 */
heap_t *heap_get_last(heap_t *root, size_t index)
{
    return (binary_tree_get_node_by_index(root, index));
}
