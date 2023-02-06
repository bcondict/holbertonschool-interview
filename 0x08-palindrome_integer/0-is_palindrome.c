#include "palindrome.h"

/**
 * get_len - get length of a given number
 *
 * @n: number to get length
 *
 * Return: length of a given number
 */

int get_len(unsigned long n)
{
	int len = 0;

	while (n > 9)
	{
		len++;
		n /= 10;
	}

	return (len);
}


/**
 * to_array - convert a long to an array
 *
 * @n: Number to convert
 *
 * Return: an array of given number in a reverse way
 */

int *to_array(unsigned long n)
{
	int i = 0;
	static int arr_long[30];
	int len = get_len(n);

	for (i = 0; i <= len; i++)
	{
		arr_long[i] = n % 10;
		n /= 10;
	}

	return (arr_long);
}


/**
 * is_palindrome - Chekc if a given number is palindrome
 *
 * @n: number to be check, type unsigned long
 *
 * Return: 1 if n is palindrome, 0 otherwise
*/

int is_palindrome(unsigned long n)
{
	int *n_arr = NULL;
	int i = 0;
	int len = get_len(n);

	n_arr = to_array(n);

	for (i = 0; len >= 0; i++)
	{
		if (n_arr[len] != n_arr[i])
			return (0);

		len--;
	}

	return (1);
}
