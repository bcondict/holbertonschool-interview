#include "substring.h"

/**
 * find_substring - finds all the possible substrings containing a list of
 *					words, within a given string.
 * @s: string to scan
 * @words: array of words all substrings must be a concatenation arrangement of
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements in the
 *
 * Return: an allocated array, storing each index in s, at which a substring
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indices = NULL, *matched = NULL;
	int word_len = 0, s_len = 0;
	int i = 0, j = 0, k = 0, l = 0;
	int found = 0;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);

	word_len = strlen(words[0]);
	s_len = strlen(s);
	indices = malloc(s_len * sizeof(int));
	matched = malloc(nb_words * sizeof(int));

	if (!indices || !matched)
		return (NULL);

	for (i = 0; i <= s_len - nb_words * word_len; i++)
	{
		memset(matched, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (!matched[k] && strncmp(s + i + j * word_len,
							words[k], word_len) == 0)
				{
					matched[k] = 1;
					found++;
					break;
				}
			}
		}
		if (found == nb_words)
			indices[l++] = i;
		found = 0;
	}
	free(matched);
	*n = l;
	return (indices);
}
