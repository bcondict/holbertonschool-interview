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
			/*ignore 0 numbers*/
			if (line[i] != 0)
			{
				/*check if there was a number before and 
				if that number is equal to current number and adds them*/
				if (last_val != 0 && last_val == line[i])
				{
					line[last_idx] = last_val + line[i];
					line[i] = 0;
				}

				/*last number found*/
				last_val = line[i];

				/*checks for index where is the last number*/
				last_idx = i;
			}
		}

	last_idx = 0;
	/*sort all the numbers to the left side*/
	for (i = 0; i < size; i++)
	{
		/*if ther's a number on index 0 skip it*/
		if (i == 0 && line[i] != 0)
			last_idx += 1;
		/*if current num is 0 and there was a number before
		saves where should be place the next num*/
		else if (line[i] == 0 && line[i - 1] != 0)
			last_idx = i;
		/*if current num is not 0 but last was,
		replace first 0 found with it*/
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
			/*ignore 0 numbers*/
			if (line[i] != 0)
			{
				/*check if there was a number before and 
				if that number is equal to current number and adds them*/
				if (last_val != 0 && last_val == line[i])
				{
					line[last_idx] = last_val + line[i];
					line[i] = 0;
				}

				/*last number found*/
				last_val = line[i];

				/*checks for index where is the last number*/
				last_idx = i;
			}
		}

	last_idx = size;
	/*sort all the numbers to the right side*/
	for (i = size - 1; i >= 0; i--)
	{
		/*ignore the first num*/
		if (i == size - 1)
			last_idx -= 1;
		/*if current is 0 and num at right is not 0
		saves it's place where need to be next num*/
		else if (line[i] == 0 && line[i + 1] != 0)
			last_idx = i;

		/*if current num is not 0 and num next to it is
		replace the first 0 found with it*/
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

	/*slide and merge to left side*/
	if (direction == 0)
	{
		slide_left(line, new_size);
	}

	/*slide and merge to right side*/
	if (direction == 1)
	{
		slide_right(line, new_size);
	}
	return (1);
}
