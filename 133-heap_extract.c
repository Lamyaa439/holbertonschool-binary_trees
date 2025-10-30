#include "binary_trees.h"

/**
 * swap_values - swaps values of two nodes
 * @a: first node
 * @b: second node
 */
void swap_values(heap_t *a, heap_t *b)
{
    int tmp = a->n;
    a->n = b->n;
    b->n = tmp;
}

/**
 * heapify_down - restores heap property downward
 * @root: pointer to root
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = root;

    if (root->left && root->left->n > largest->n)
        largest = root->left;
    if (root->right && root->right->n > largest->n)
        largest = root->right;

    if (largest != root)
    {
        swap_values(root, largest);
        heapify_down(largest);
    }
}

/**
 * heap_extract - extracts max value from Max Binary Heap
 * @root: double pointer to heap root
 * Return: value of removed node or 0 if fail
 */
int heap_extract(heap_t **root)
{
    heap_t *last, *node;
    int value;

    if (!root || !*root)
        return (0);

    node = *root;
    value = node->n;

    last = heap_get_last(*root);

    if (last == *root)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    (*root)->n = last->n;

    if (last->parent->right == last)
        last->parent->right = NULL;
    else
        last->parent->left = NULL;

    free(last);
    heapify_down(*root);

    return (value);
}
