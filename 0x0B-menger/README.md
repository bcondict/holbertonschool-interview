# 0x0B. Menger sponge

Here is the task I solve to practive interview excercise. The solution the task is on the file with the same name than the task.

My challenge for you is to try to solve all of this task and after see the way I did it.


#### 0. 2D Menger sponge
Write a function that draws a 2D Menger Sponge

- Prototype: `void menger(int level)`;
- Where `level` is the level of the Menger Sponge to draw
- If `level` is lower than `0`, your function must do nothing
- You’re allowed to use the `math` library. Your program will be compiled using the `ld` flag `-lm`
Format:

    - First, read [Menger sponge](https://en.wikipedia.org/wiki/Menger_sponge)
    - Here, we will only draw a 2D version of the Menger sponge, but the principle is the same
    - A level `N` sponge is a 3x3 square of level `N-1` sponges, except for the center one, which is left empty
    - A level 0 sponge is represented by the `#` character
    - Examples:
        - A level 0 sponge is a simple 1x1 square
        - A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
        - A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty
        - …
    - TIP: The size of a level N Menger sponge is calculated as follows: 3^N

#### COMPILER GCC
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm

#### Usage
```sh
$ ./0-menger 0
#
$ ./0-menger 1
###
# #
###
$ ./0-menger 2
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```

#### MAIN
```c
#include "menger.h"

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
    int level;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s level\n", av[0]);
        return (EXIT_FAILURE);
    }

    level = atoi(av[1]);
    menger(level);

    return (EXIT_SUCCESS);
}
```
