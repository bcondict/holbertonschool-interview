#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Libraries */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/* Structures */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 *
 * Description: Binary tree node structure
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

/* Prototypes */
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

#endif /* BINARY_TREES_H */
