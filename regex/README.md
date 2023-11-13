# RegEx

Here is the task I solve to practive interview excercise. The solution the task is on the file with the same name than the task.

My challenge for you is to try to solve all of this task and after see the way I did it.

All the intellectual property belongs to Holberton School.

## Requirements
### C
- Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl)
- You are not allowed to use global variables
- No more than 5 functions per file
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `regex.h`
- Don’t forget to push your header file
- All your header files should be include guarded

## Tasks
#### 0. Simple RegEx
Write a function that checks whether a given pattern matches a given string.

- Prototype: `int regex_match(char const *str, char const *pattern);`, where:
    - `str` is the string to scan
    - `pattern` is the regular expression
- Your function must return 1 if the pattern matches the string, or `0` if it doesn’t
- `str` can be empty, and can contain any ASCII character in the exception of `.` and `*`
- `pattern` can be empty, and can contain any ASCII character, including `.` and `*`
- The regular expression matching must support the characters `.` and `*`
    - `.` matches any single character
    - `*` matches zero or more of the preceding character

### Compiler
```bash
gcc -Wall -Wextra -Werror -pedantic main.c regex.c
```

### Example
```bash
./a.out
H -> H = 1
HH -> H = 0
HH -> H* = 1
HHHHHHHHHHHHHHHHH -> H* = 1
Holberton -> .* = 1
Alex -> .* = 1
Guillaume -> .* = 1
Julien -> .* = 1
Holberton -> Z*H.* = 1
Holberton -> Z*H.*olberton = 1
Holberton -> Z*H.*o. = 1
Holberton -> Z*H.*o = 0
Holberton -> holberton = 0
Holberton -> .olberton = 1
!H@o#l$b%e^r&t(o)n_ -> !.@.#.$.%.^.&.(.)._ = 1
```

