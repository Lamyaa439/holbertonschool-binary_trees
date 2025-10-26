# .binary_trees
A comprehensive implementation of **Binary Trees** in C.  
This repository contains data structures and functions to create, traverse, measure, and validate binary trees — aligned with Holberton School requirements and the Betty style.

---

## Project Description
A **binary tree** is a hierarchical data structure where each node has at most two children: `left` and `right`.  
This project implements core operations and utilities for working with binary trees, including:

- Creating and linking nodes  
- Inserting children (left/right)  
- Traversing the tree (preorder, inorder, postorder)  
- Measuring **height**, **depth**, **size**  
- Counting **leaves** and **internal nodes**  
- Computing **balance factor**  
- Checking whether a tree is **full** or **perfect**  
- Finding **sibling** and **uncle** nodes  
- Printing the tree in a readable 2D layout (via `binary_tree_print` helper)

> Target OS: Ubuntu 20.04 LTS  
> Compiler: `gcc -Wall -Werror -Wextra -pedantic`  
> Style: **Betty**

---

## Data Structures & Variables

### `struct binary_tree_s`
The central node structure for all tree variants in this project.

```c
/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;
```

| Field | Type | Meaning |
|-------|------|----------|
| `n` | `int` | The value stored in the node. |
| `parent` | `struct binary_tree_s*` | Pointer to the parent node (or `NULL` for the root). |
| `left` | `struct binary_tree_s*` | Pointer to the left child (or `NULL` if none). |
| `right` | `struct binary_tree_s*` | Pointer to the right child (or `NULL` if none). |

---

## Functions Overview

| File | Prototype | Description |
|------|------------|-------------|
| `0-binary_tree_node.c` | `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);` | Creates a new binary tree node. |
| `1-binary_tree_insert_left.c` | `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);` | Inserts a node as `parent->left`. |
| `2-binary_tree_insert_right.c` | `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);` | Inserts a node as `parent->right`. |
| `3-binary_tree_delete.c` | `void binary_tree_delete(binary_tree_t *tree);` | Frees an entire binary tree. |
| `4-binary_tree_is_leaf.c` | `int binary_tree_is_leaf(const binary_tree_t *node);` | Checks if a node is a leaf. |
| `5-binary_tree_is_root.c` | `int binary_tree_is_root(const binary_tree_t *node);` | Checks if a node is the root. |
| `6-binary_tree_preorder.c` | `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));` | Preorder traversal: node → left → right. |
| `7-binary_tree_inorder.c` | `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));` | Inorder traversal: left → node → right. |
| `8-binary_tree_postorder.c` | `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));` | Postorder traversal: left → right → node. |
| `9-binary_tree_height.c` | `size_t binary_tree_height(const binary_tree_t *tree);` | Measures the height of a binary tree. |
| `10-binary_tree_depth.c` | `size_t binary_tree_depth(const binary_tree_t *node);` | Measures the depth of a node. |
| `11-binary_tree_size.c` | `size_t binary_tree_size(const binary_tree_t *tree);` | Counts all nodes in the tree. |
| `12-binary_tree_leaves.c` | `size_t binary_tree_leaves(const binary_tree_t *tree);` | Counts leaves in a tree. |
| `13-binary_tree_nodes.c` | `size_t binary_tree_nodes(const binary_tree_t *tree);` | Counts nodes with at least one child. |
| `14-binary_tree_balance.c` | `int binary_tree_balance(const binary_tree_t *tree);` | Calculates balance factor. |
| `15-binary_tree_is_full.c` | `int binary_tree_is_full(const binary_tree_t *tree);` | Checks if a tree is full. |
| `16-binary_tree_is_perfect.c` | `int binary_tree_is_perfect(const binary_tree_t *tree);` | Checks if a tree is perfect. |
| `17-binary_tree_sibling.c` | `binary_tree_t *binary_tree_sibling(binary_tree_t *node);` | Finds a node’s sibling. |
| `18-binary_tree_uncle.c` | `binary_tree_t *binary_tree_uncle(binary_tree_t *node);` | Finds a node’s uncle. |

---

## Build & Run

### Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o binary_trees
```

### Example
```c
#include "binary_trees.h"

int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 56);

    binary_tree_print(root);
    binary_tree_delete(root);
    return (0);
}
```

Output:
```
     98
    /    12    402
  /  6  56
```

---

## Key Definitions
- **Depth(node):** Number of edges from the node to the root.  
- **Height(tree):** Longest path from the root to a leaf.  
- **Size(tree):** Total number of nodes.  
- **Balance Factor:** `height(left) - height(right)`

---

## Example Traversal Implementation
```c
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree && func)
    {
        func(tree->n);
        binary_tree_preorder(tree->left, func);
        binary_tree_preorder(tree->right, func);
    }
}
```

---

## Authors
**Lamyaa**  **Lina**
(Lamyaa439) (linawsm52)
