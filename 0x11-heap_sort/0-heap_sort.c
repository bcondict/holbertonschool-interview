#include "sort.h"

/**
 * heapify - builds a heap from an array
 * @array: array to be sorted
 * @size: size of the array
 * @i: index
 * @total_size: total size of the array
*/
void heapify(int *array, int size, int i, int total_size)
{
	int largest = i, left = 2 * i + 1, right = 2 * i + 2, temp;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
