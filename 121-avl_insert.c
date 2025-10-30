#include "binary_trees.h"

/**
 * _avl_insert - recursive insert and rebalance
 * @tree: pointer to pointer to root
 * @value: value to insert
 * Return: pointer to inserted node or NULL
 */
binary_tree_t *_avl_insert(binary_tree_t **tree, int value)
{
    binary_tree_t *node;

    if (*tree == NULL)
        return (*tree = binary_tree_node(NULL, value));

    if (value < (*tree)->n)
    {
        node = _avl_insert(&(*tree)->left, value);
        if (node == NULL)
            return (NULL);
        (*tree)->left->parent = *tree;
    }
    else if (value > (*tree)->n)
    {
        node = _avl_insert(&(*tree)->right, value);
        if (node == NULL)
            return (NULL);
        (*tree)->right->parent = *tree;
    }
    else
        return (NULL);

    /* Balance */
    if (binary_tree_balance(*tree) > 1)
    {
        if (value < (*tree)->left->n)
            *tree = binary_tree_rotate_right(*tree);
        else
        {
            (*tree)->left = binary_tree_rotate_left((*tree)->left);
            (*tree)->left->parent = *tree;
            *tree = binary_tree_rotate_right(*tree);
        }
    }
    else if (binary_tree_balance(*tree) < -1)
    {
        if (value > (*tree)->right->n)
            *tree = binary_tree_rotate_left(*tree);
        else
        {
            (*tree)->right = binary_tree_rotate_right((*tree)->right);
            (*tree)->right->parent = *tree;
            *tree = binary_tree_rotate_left(*tree);
        }
    }

    return (node);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: pointer to pointer to root of tree
 * @value: value to insert
 * Return: pointer to created node or NULL
 */
binary_tree_t *avl_insert(binary_tree_t **tree, int value)
{
    if (tree == NULL)
        return (NULL);

    return (_avl_insert(tree, value));
}
