#include "binary_trees.h"

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively
 * @tree: Double pointer to the root node of the AVL tree
 * @value: The value to insert into the tree
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
binary_tree_t *avl_insert_recursive(binary_tree_t **tree, int value)
{
    binary_tree_t *node;

    if (*tree == NULL)
        return (*tree = binary_tree_node(NULL, value));

    if (value < (*tree)->n)
    {
        node = avl_insert_recursive(&((*tree)->left), value);
        if (node == NULL)
            return (NULL);
        (*tree)->left->parent = *tree;
    }
    else if (value > (*tree)->n)
    {
        node = avl_insert_recursive(&((*tree)->right), value);
        if (node == NULL)
            return (NULL);
        (*tree)->right->parent = *tree;
    }
    else
        return (NULL);

    /* Balance check */
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
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 * @value: The value to insert
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
binary_tree_t *avl_insert(binary_tree_t **tree, int value)
{
    if (tree == NULL)
        return (NULL);

    return (avl_insert_recursive(tree, value));
}
