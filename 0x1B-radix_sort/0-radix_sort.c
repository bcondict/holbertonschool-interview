#include "sort.h"

/**
 * find_max - find the maximum number in an array
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Maximum number in array
*/
int find_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * count_sort - sorts an array of integers in ascending order
 *				using the Counting sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 * @exp: exponent of the number to power
 *
 * Return: Always void
*/
void count_sort(int *array, size_t size, int exp)
{
	int *output = NULL;
	int count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int) i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 *				using the Radix sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Always void
*/
void radix_sort(int *array, size_t size)
{
	int max = 0;
	int exp = 0;

	if (!array || size < 2)
		return;

	max = find_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
