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

	merge_sort_recursive(array, copy, size);
	free(copy);
}

/**
 * merge_sort_recursive - Sorts an array of integers in ascending order using
 * the Merge Sort algorithm
 *
 * @array: The array to be sorted
 * @copy: copy of array
 * @end: end of array
 *
 * Return: Nothing
 */
void merge_sort_recursive(int *array, int *copy, int end)
{
	int mid = end / 2;

	if (end <= 1)
		return;

	merge_sort_recursive(array, copy, mid);
	merge_sort_recursive(&array[mid], copy, end - mid);
	merge(array, copy, mid, end);
}

/**
 * merge - Merges two subarrays of integers in ascending order
 *
 * @array: The array to be sorted
 * @copy: copy of array
 * @mid: middle part of array
 * @end: end of array
 *
 * Return: Nothing
*/
void merge(int *array, int *copy, int mid, int end)
{
	int left = 0, right = mid, index = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(&array[mid], end - mid);

	for (index = 0, right = mid; left < mid && right < end; index++)
	{
		if (array[left] <= array[right])
		{
			copy[index] = array[left];
			left++;
		}
		else
		{
			copy[index] = array[right];
			right++;
		}
	}

	while (left < mid)
	{
		copy[index] = array[left];
		index++, left++;
	}

	while (right <= end)
	{
		copy[index] = array[right];
		index++, right++;
	}

	for (index = 0; index < end; index++)
		array[index] = copy[index];

	printf("[Done]: ");
	print_array(array, end);
}
