#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size) 
{
	int *copy;

	if (array == NULL || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	merge_sort_recursive(array, copy, 0, size - 1);
	free(copy);
}

/**
 * merge_sort_recursive - Sorts an array of integers in ascending order using
 * the Merge Sort algorithm
 *
 * @array: The array to be sorted
 * @copy: copy of array
 * @start: start of array
 * @end: end of array
 *
 * Return: Nothing
 */
void merge_sort_recursive(int *array, int *copy, int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start  + end) / 2;
		merge_sort_recursive(array, copy, start, mid);
		merge_sort_recursive(array, copy, mid + 1, end);
		merge(array, copy, start, mid, end);
	}
}

/**
 * merge - Merges two subarrays of integers in ascending order
 *
 * @array: The array to be sorted
 * @copy: copy of array
 * @start: left part of array
 * @mid: middle part of array
 * @end: end of array
 *
 * Return: Nothing
*/
void merge(int *array, int *copy, int start, int mid, int end)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start + 1);
	printf("[right]: ");
	print_array(array + mid + 1, end - mid);

	for (i = start, j = mid + 1, k = start; i <= mid && j <= end; k++)
	{
		if (array[i] <= array[j])
			copy[k] = array[i++];
		else
			copy[k] = array[j++];
	}

	while (i <= mid)
		copy[k++] = array[i++];

	while (j <= end)
		copy[k++] = array[j++];

	for (i = start; i <= end; i++)
		array[i] = copy[i];

	printf("[Done]: ");
	print_array(array + start, end - start + 1);
}

