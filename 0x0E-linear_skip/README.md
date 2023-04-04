# 0x0E. Linear search in skip list

Here is the task I solve to practive interview excercise. The solution the task is on the file with the same name than the task.

My challenge for you is to try to solve all of this task and after see the way I did it.

- main file is used to test the task.
- create_skiplist is a function to create a skip list with an array of integer.
- free_skiplist is a function to free the skip list.
- print_skiplist is a function to print the skip list.
- search.h is a header file with the prototypes of the functions.

All the intellectual property belongs to Holberton School.

## Taks
#### 0. Linear search in a skip list
Looking for a specific value in a singly linked list always leads to browse every element of the list. A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it. A linked list with an express lane is called a [skip list](https://en.wikipedia.org/wiki/Skip_list).

Write a function that searches for a value in a sorted skip list of integers.
- Prototype : `skiplist_t *linear_skip(skiplist_t *list, int value);`
- Where `list` is a pointer to the head of the skip list to search in
- A node of the express lane is placed every index which is a multiple of the square root of the size of the list (see example below)
- And `value` is the value to search for
- You can assume that `list` will be sorted in ascending order
- Your function must return a pointer on the first node where `value` is located
- If `value` is not present in `list` or if `head` is NULL, your function must return `NULL`
- Every time you compare a value in the list to the value you are searching, you have to print this value (see example below)

NOTE: [You can find here](https://github.com/hs-hq/0x0E.Linear_search-in_skip_list) the functions used in the example. You don’t need to push them, we will compile your file with our own implementation during the correction. BUT, **don’t forget to push** `search.h`


## compiler
gcc gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c *skiplist.c -lm -o 0-linear_skip

## Usage
```sh
./0-linear_skip
List :
Index[0] = [0]
Index[1] = [1]
Index[2] = [2]
Index[3] = [3]
Index[4] = [4]
Index[5] = [7]
Index[6] = [12]
Index[7] = [15]
Index[8] = [18]
Index[9] = [19]
Index[10] = [23]
Index[11] = [53]
Index[12] = [61]
Index[13] = [62]
Index[14] = [76]
Index[15] = [99]

Express lane :
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11

Value checked at index [4] = [4]
Value found between indexes [0] and [4]
Value checked at index [0] = [0]
Value checked at index [1] = [1]
Value checked at index [2] = [2]
Found 2 at index: 2

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [12] and [15]
Value checked at index [12] = [61]
Value checked at index [13] = [62]
Value checked at index [14] = [76]
Value checked at index [15] = [99]
Found 999 at index: (nil)
```
