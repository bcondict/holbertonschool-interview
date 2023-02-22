#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_

/* Libraries */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/* Macros */
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

/* Prototypes */
int slide_line(int *line, size_t size, int direction);

#endif /*_SLIDE_LINE_H_*/
