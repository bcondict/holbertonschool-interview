# 0x12. Advanced Binary Search

Here is the task I solve to practive interview excercise. The solution the task is on the file with the same name than the task.

My challenge for you is to try to solve all of this task and after see the way I did it.

All the intellectual property belongs to Holberton School.

### Requirements
#### General
- Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- You are only allowed to use the `printf` function of the standard library. Any call to another function like `strdup`, `malloc`, … is forbidden.

### Task
#### 0. Advanced Binary Search
You may have noticed that basic binary search does not necessarily return the index of the first value in the array (if this value appears more than once in the array). In this exercise, you’ll have to solve this problem.

Write a function that searches for a value in a sorted array of integers.
- Prototype: `int advanced_binary(int *array, size_t size, int value);`
- `array` is a pointer to the first element of the array to search in
- `size` is the number of elements in `array`
- `value` is the value to search for
- Your function must return the index where `value` is located
- You can assume that `array` will be sorted in ascending order
- If `value` is not present in `array` or if `array` is `NULL`, your function must return `-1`
- Every time you split the array, you have to print the new array (or subarray) you’re searching in (See example)
- You have to use recursion. You may only use one loop (`while`, `for`, `do while`, etc.) in order to print the array

### Compiler
```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o 0-advanced_binary
```

### Usage
```bash
$ ./0-advanced_binary
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```
