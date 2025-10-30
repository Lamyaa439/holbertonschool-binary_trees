#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/* Basic binary tree functions */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
void binary_tree_print(const binary_tree_t *);

/* Heap functions */
binary_tree_t *heap_insert(heap_t **root, int value);
binary_tree_t *binary_tree_get_node_by_index(binary_tree_t *root, size_t index);
size_t binary_tree_size(const binary_tree_t *tree);
binary_tree_t *heap_get_last(binary_tree_t *root);
int heap_extract(heap_t **root);

/* Advanced */
heap_t *array_to_heap(int *array, size_t size);

#endif /* BINARY_TREES_H */
