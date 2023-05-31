#include "holberton.h"

/**
 * main - Entry point
 *
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	char *num1 = NULL, *num2 = NULL;
	char *result = NULL;
	int i = 0;

	if (argc != 3)
		print_error();

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; i < str_len(num1); i++)
	{
		if (!is_digit(num1[i]))
			print_error();
	}

	for (i = 0; i < str_len(num2); i++)
	{
		if (!is_digit(num2[i]))
			print_error();
	}

	result = multiply(num1, num2);
	print_result(result);

	return (0);
}
