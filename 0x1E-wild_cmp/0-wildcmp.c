#include "holberton.h"

/**
 * wildcmp - compares two strings
 * "*" can be replaced with any string (including an empty string)
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	/* if s1 and s2 are empty*/
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* if s1 is empty and s2 is '*' */
	if (*s1 == '\0' && *s2 == '*')
		return (wildcmp(s1, s2 + 1));

	/* if one string is empty */
	if (*s1 == '\0' || *s2 == '\0')
		return (0);

	/* if the characters match */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* if s2 is '*' */
	if (*s2 == '*')
	{
		/* if the next character is '*' */
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		/* if the next character matches */
		if (wildcmp(s1 + 1, s2) == 1)
			return (1);

		/* if the next character doesn't match */
		return (wildcmp(s1, s2 + 1));
	}

	return (0);
}
