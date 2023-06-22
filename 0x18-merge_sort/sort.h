#ifndef _SORT_H_
#define _SORT_H_

/* Libraries */
#include <stdio.h>
#include <stdlib.h>

/* Prototypes */
void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, int *copy, int iBegin, int iEnd);
void merge(int *array, int *copy, int iBegin, int iMiddle, int iEnd);

#endif /* _SORT_H_ */
