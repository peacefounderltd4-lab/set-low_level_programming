# 0x00. Hello World

This project introduces the basics of C programming.

## Task 0: Preprocessor

A Bash script that runs a C file through the preprocessor and saves the result into a file named `c`.

### Requirements
- Ubuntu 20.04 LTS
- gcc with flags: -Wall -Werror -Wextra -pedantic -std=gnu89

### Script
The script uses:
gcc -E $CFILE > c

`$CFILE` contains the name of the C source file.
