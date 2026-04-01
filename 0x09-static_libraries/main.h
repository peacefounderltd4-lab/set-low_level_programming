#!/bin/bash
# Create object files
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c *.c

# Create static library
ar rcs liball.a *.o

# Optional: clean object files
rm *.o
