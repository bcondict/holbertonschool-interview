#include "slide_line.h"

/**
 * slide_left - slide and merge to the left side
 *
 * @line: points to an array of integers
 * @size: count of elements inside line
 *
 * Return: Always void
 */

void slide_left(int *line, int size)
{
	int i = 0;
	int last_idx = 0;
	int last_val = 0;

	/*sum all the possible numbers without order and save it on left num*/
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (last_val != 0 && last_val == line[i])
			{
				line[last_idx] = last_val + line[i];
				line[i] = 0;
			}
			last_val = line[i];
			last_idx = i;
		}
	}

	last_idx = 0;
	/*
	*sort all the numbers to the left side
	* saving first occurrence and place num in it
	*/
	for (i = 0; i < size; i++)
	{
		if (i == 0 && line[i] != 0)
			last_idx += 1;
		else if (line[i] == 0 && line[i - 1] != 0)
			last_idx = i;
		else if (line[i] != 0 && line[i - 1] == 0)
		{
			line[last_idx] = line[i];
			last_idx += 1;
			line[i] = 0;
		}
	}
}

/**
 * slide_right - slide and merge to the right side
 *
 * @line: points to an array of integers
 * @size: count of elements inside line
 *
 * Return: Always void
 */

void slide_right(int *line, int size)
{
	int i = 0;
	int last_idx = 0;
	int last_val = 0;

	/*sum all the possible numbers without order and save it on right num*/
	for (i = size; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (last_val != 0 && last_val == line[i])
			{
				line[last_idx] = last_val + line[i];
				line[i] = 0;
			}
			last_val = line[i];
			last_idx = i;
		}
	}

	last_idx = size;
	/*
	* sort all the numbers to the right side
	* saving first occurrence and place num in it
	*/
	for (i = size - 1; i >= 0; i--)
	{
		if (i == size - 1)
			last_idx -= 1;
		else if (line[i] == 0 && line[i + 1] != 0)
			last_idx = i;
		else if (line[i] != 0 && line[i + 1] == 0)
		{
			line[last_idx] = line[i];
			last_idx -= 1;
			line[i] = 0;
		}
	}
}

/**
 * slide_line - function that slides and merges an array of integer
 *
 * @line: points to an array of integers
 * @size: count of elements inside line
 * @direction: directo to slide and merge int inside line
 *
 * Return: 1 upon success, 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	int new_size = (int) size;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	/*slide and merge to left side*/
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, new_size);
	}

	/*slide and merge to right side*/
	if (direction == SLIDE_RIGHT)
	{
		slide_right(line, new_size);
	}
	return (1);
}
