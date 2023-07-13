# 0x1A. double circular linked list

Here is the task I solve to practive interview excercise. The solution the task is on the file with the same name than the task.

My challenge for you is to try to solve all of this task and after see the way I did it.

All the intellectual property belongs to Holberton School.

## Requirements
### General
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl)
- You are not allowed to use global variables
- No more than 5 functions per file
- The only C standard library functions allowed are `malloc`, `free`, and `exit`. Any use of functions like `printf`, `puts`, `calloc`, `realloc` etc… is forbidden
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `list.h`
- Don’t forget to push your header file
- All your header files should be include guarded

## More Info
Please use this data structure for this project:

```c
/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
    char *str;
    struct List *prev;
    struct List *next;
} List;
```

## Tasks
#### 0. Add Nodes
Create the source file `0-add_node.c` that contains the following functions:

- Add a new node to **the end** of a double circular linked list:
    - Prototype: `List *add_node_end(List **list, char *str);`
    - `List`: the list to modif
        - `str`: the string to copy into the new node
        - Returns: Address of the new node, or `NULL` on failure
- Add a new node to **the beginning** of a double circular linked list:
    - Prototye: `List *add_node_begin(List **list, char *str);`
    - `List`: the list to modify
        - `str`: the string to copy into the new node
        - Returns: Address of the new node, or `NULL` on failure

### Compiler
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-add_node.c
```

### Example
```bash
$ ./a.out
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
Added to the beginning:
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
```

## Author
@bcondict
