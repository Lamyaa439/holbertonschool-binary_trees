#include "binary_trees.h"

/**
 * avl_insert_recursive - recursive insert and rebalance
 * @tree: double pointer to root
 * @value: value to insert
 * Return: pointer to inserted node or NULL
 */
binary_tree_t *avl_insert_recursive(avl_t **tree, int value)
{
    binary_tree_t *node;

    if (*tree == NULL)
        return (*tree = binary_tree_node(NULL, value));

    if (value < (*tree)->n)
    {
        node = avl_insert_recursive(&((*tree)->left), value);
        if (!node)
            return (NULL);
        (*tree)->left->parent = *tree;
    }
    else if (value > (*tree)->n)
    {
        node = avl_insert_recursive(&((*tree)->right), value);
        if (!node)
            return (NULL);
        (*tree)->right->parent = *tree;
    }
    else
        return (NULL);

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
 * @tree: pointer to pointer to root node
 * @value: value to insert
 * Return: pointer to created node or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (!tree)
        return (NULL);

    return (avl_insert_recursive(tree, value));
}
