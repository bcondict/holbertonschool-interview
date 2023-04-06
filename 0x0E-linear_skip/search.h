#ifndef _SEARCH_H_
#define _SEARCH_H_

/* libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

/* structures */
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/* prototypes */
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* _SEARCH_H_ */
