# 0x07. Pointers, arrays and strings

This project implements various functions in C that manipulate pointers, arrays, and strings, with manual implementation of some standard C library functions.

## Functions implemented

- _memset: fills memory with a constant byte.
- _memcpy: copies memory area.
- _strchr: locates a character in a string.
- _strspn: gets length of a prefix substring.
- _strpbrk: searches a string for any of a set of bytes.
- _strstr: locates a substring.
- print_chessboard: prints an 8x8 chessboard.
- print_diagsums: prints the sum of the two diagonals of a square matrix.

## Requirements

- Code follows Betty coding style and documentation.
- No global variables.
- Allowed functions: write, printf, putchar, puts, malloc, free.
- Compilation with gcc using flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Use `_putchar` for output where required.
- No use of standard library functions for the main implementations.

## Usage

Compile with:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o program_name


Test each function with the corresponding main files provided in the project.
