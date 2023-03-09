#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge to draw
 *
 * Return: Void
 */

void menger(int level)
{
	int height, lenght = 0;
	int size = pow(3, level);
	int sub_height, sub_lenght = 0;
	char to_print;

	if (level < 0)
		return;

	/*go over height*/
	for (height = 0; height < size; height++)
	{
		/*go over length*/
		for (lenght = 0; lenght < size; lenght++)
		{
			/*asign char to print every iteration*/
			to_print = '#';
			sub_height = height;
			sub_lenght = lenght;
			while (sub_height > 0 || sub_lenght > 0)
			{
				/*check if module of current len and curret hieght is 1*/
				if (sub_height % 3 == 1 && sub_lenght % 3 == 1)
				{
					/*change character to print to empty*/
					to_print = ' ';
				}
				/*divides size to print*/
				sub_height /= 3;
				sub_lenght /= 3;
			}
			printf("%c", to_print);
		}
		printf("\n");
	}
}
