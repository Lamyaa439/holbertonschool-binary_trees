#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: double pointer to root of heap
 * @value: value to insert
 * Return: pointer to inserted node, or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new, *parent;
    size_t size, parent_index;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    size = binary_tree_size(*root) + 1;
    parent_index = size / 2;

    parent = binary_tree_get_node_by_index(*root, parent_index);
    if (!parent)
        return (NULL);

    new = binary_tree_node(parent, value);
    if (!new)
        return (NULL);

    if (!parent->left)
        parent->left = new;
    else
        parent->right = new;

    while (new->parent && new->n > new->parent->n)
    {
        int tmp = new->n;
        new->n = new->parent->n;
        new->parent->n = tmp;
        new = new->parent;
    }

    return (new);
}
