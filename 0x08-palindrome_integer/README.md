# 0x08. Palindrome integer

Write a function that checks whether or not a given unsigned integer is a palindrome.
- Prototype: `int is_palindrome(unsigned long n)`
- Where `n` is the number to be checked
- Your function must return `1` if `n` is palindrome, and `0` otherwise
- You are **not allowed** to allocate memory dynamically (malloc, calloc, ...)

#### Main
```c
#include "palindrome.h"

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    unsigned long n;
    int ret;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s arg\n", av[0]);
        return (EXIT_FAILURE);
    }

    n = (unsigned long)(atol(av[1]));
    ret = is_palindrome(n);

    printf("%lu is ", n);
    if (ret == 0)
        printf("not ");
    printf("a palindrome.\n");

    return (EXIT_SUCCESS);
}
```
