#include "holberton.h"


/**
 * str_len - returns the length of a string
 *
 * @str: string to check
 *
 * Return: length of str
 */
int str_len(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * print_error - prints "Error" and exits with status 98
 *
 * Return: always nothing
 */
void print_error(void)
{
	char *error_msg = "Error\n";
	int len = str_len(error_msg);
	int i;

	for (i = 0; i < len; i++)
		_putchar(error_msg[i]);

	exit(98);
}

/**
 * print_result - prints a string
 *
 * @result: string to print
 *
 * Return: always nothing
 */
void print_result(char *result)
{
	int len = str_len(result);
	int i = 0;

	for (i = 0; i < len; i++)
		_putchar(result[i]);

	_putchar('\n');
}

/**
 * multiply - multiplies two positive numbers
 *
 * @num1: first number
 * @num2: second number
 *
 * Return: pointer to the result, or NULL on failure
 */
char *multiply(char *num1, char *num2)
{
	int len1 = str_len(num1);
	int len2 = str_len(num2);
	int res_len = len1 + len2, temp = 0;
	char *result = NULL;
	int i = 0, j = 0, carry = 0;

	result = malloc((res_len + 1) * sizeof(char));
	if (result == NULL)
		print_error();

	for (i = 0; i < res_len; i++)
		result[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			temp = (num1[i] - '0') * (num2[j] - '0')
					+ (result[i + j + 1] - '0') + carry;
			result[i + j + 1] = temp % 10 + '0';
			carry = temp / 10;
		}
		result[i] += carry;
	}

	if (result[0] == '0')
	{
		return (result + 1);
	}

	return (result);
}

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
		if (!(num1[i] >= '0' && num1[i] <= '9'))
			print_error();
	}

	for (i = 0; i < str_len(num2); i++)
	{
		if (!(num2[i] >= '0' && num2[i] <= '9'))
			print_error();
	}

	result = multiply(num1, num2);
	print_result(result);

	return (0);
}
