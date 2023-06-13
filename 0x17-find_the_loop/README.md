# 0x17. Find the loop

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
- No standard library functions allowed. Any use of functions like `printf`, `puts`, `calloc`, `realloc` etc… is forbidden
- The prototypes of all your functions should be included in your header files called `lists.h`
- Don’t forget to push your header file
- All your header files should be include guarded
- Please use this `lists.h`:
```c
#ifndef _LISTS_H_
#define _LISTS_H_

#include <stddef.h>


/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);

listint_t *find_listint_loop(listint_t *head);

#endif
```

## Tasks
#### 0. Find the loop
Write a function that findes the loop in a linked lists.

- Prototype: `listint_t *find_listint_loop(listint_t *head);`
- Returns: The address of the node where the loop starts, or `NULL` if there is no loop
- You are not allowed to use `malloc`, `free` or arrays
- You can only declare a maximum of two variables in your function

Node: in order to compile the main file, you are provided with [this static library](https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/interviews/472/libloop.a). This library won't be used during the correction; It's only purpose is for testing.

If you want to use source file instead of the `libloop.a` library, please use this file [lib.c](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/text/2021/1/79eebf4f9215073644b8cd766a88c8a3f3a0fd88.c?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20230613%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20230613T125457Z&X-Amz-Expires=345600&X-Amz-SignedHeaders=host&X-Amz-Signature=2dbb1dbaae7ed3e1c25891e26e79da31e29cf359bb6a062de027dc6ac263baeb)

### Compiler
```bash
$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main
```

### Example
```bash
$ ./main
[0x13700f0] 1024
[0x13700d0] 402
[0x13700b0] 98
[0x1370090] 4
[0x1370070] 3
[0x1370050] 2
[0x1370030] 1
[0x1370010] 0
[0x1370560] 1024
[0x1370540] 402
[0x1370010] 98
[0x1370030] 7
[0x1370050] 6
[0x1370070] 5
[0x1370090] 4
[0x13700b0] 3
[0x13700d0] 2
[0x13700f0] 1
[0x1370110] 0
-> [0x1370030] 7
Loop starts at [0x1370030] 7
```
