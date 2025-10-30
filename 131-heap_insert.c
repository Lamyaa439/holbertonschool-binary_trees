#include "binary_trees.h"

/* ====== helpers kept local (static) because checker compiles a single file ====== */

/**
 * tree_size - computes number of nodes in a binary tree
 * @tree: root
 * Return: size (0 if NULL)
 */
static size_t tree_size(const binary_tree_t *tree)
{
        if (!tree)
                return (0);
        return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * parent_by_index - navigate to the parent of the position where the next node
 * should be inserted in a complete binary tree using the BFS index.
 *
 * We compute the index of the new node as (size + 1) then take parent index:
 * p = index / 2. We walk the bit-path of p from the second highest bit to LSB:
 * 0 => go left, 1 => go right.
 *
 * @root: heap root
 * @pidx: parent index (>= 1)
 * Return: pointer to parent node (never NULL for a valid complete tree)
 */
static heap_t *parent_by_index(heap_t *root, size_t pidx)
{
        size_t msb = 1;

        /* find highest set bit */
        while ((msb << 1) <= pidx)
                msb <<= 1;

        /* skip the msb (root), walk remaining bits */
        for (msb >>= 1; msb; msb >>= 1)
        {
                if (pidx & msb)
                        root = root->right;
                else
                        root = root->left;
        }
        return (root);
}

/**
 * heap_bubble_up - swap values upwards to restore Max-Heap property
 * @node: recently inserted node
 * Return: final position of the inserted value
 */
static heap_t *heap_bubble_up(heap_t *node)
{
        while (node->parent && node->n > node->parent->n)
        {
                int tmp = node->n;

                node->n = node->parent->n;
                node->parent->n = tmp;
                node = node->parent;
        }
        return (node);
}

/* ========================= public API required by the task ===================== */

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: double pointer to the heap root
 * @value: value to insert
 * Return: pointer to the inserted node (final position), or NULL on failure
 *
 * Notes:
 * - The new node is first appended at the next position that preserves
 *   completeness (BFS order), then we bubble-up by swapping values.
 * - No extra helper files are needed; all helpers are static in this file
 *   because the checker only compiles 131-heap_insert.c and 0-binary_tree_node.c
 */
heap_t *heap_insert(heap_t **root, int value)
{
        heap_t *parent, *node;
        size_t sz, pidx;

        if (!root)
                return (NULL);

        if (!*root)
        {
                *root = binary_tree_node(NULL, value);
                return (*root);
        }

        /* next index in a complete tree and its parent index */
        sz = tree_size(*root) + 1;
        pidx = sz / 2;

        parent = parent_by_index(*root, pidx);
        if (!parent)
                return (NULL);

        node = binary_tree_node(parent, value);
        if (!node)
                return (NULL);

        if (!parent->left)
                parent->left = node;
        else
                parent->right = node;

        return (heap_bubble_up(node));
}
