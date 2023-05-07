#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * using the Binary search algorithm - only the first index where value is
 * located is returned
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if value is not present
 * in array or if array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid, offset = 0;
	int tmp;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
		printf("%d%s", array[i], i == size - 1 ? "\n" : ", ");

	if (size == 1 && array[0] != value)
		return (-1);

	mid = (size - 1) / 2;
	if (array[mid] == value)
	{
		if (array[mid - 1] < value)
			return (mid);
		return (advanced_binary(array, mid + 1, value));
	}

	if (array[mid] < value)
	{
		offset += mid + 1;
		array += mid + 1;
		if (size % 2 != 0)
			mid--;
	}

	mid++;
	tmp = advanced_binary(array, mid, value);
	if (tmp != -1)
		return (tmp + offset);

	return (-1);
}
