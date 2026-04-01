#!/bin/bash
# create_static_lib.sh
# Creates a static library liball.a from all .c files in the current directory

# Remove existing liball.a if it exists to avoid appending
if [ -f liball.a ]; then
    rm -f liball.a
fi

# Compile all .c files into object files
for file in *.c; do
    gcc -c "$file" -o "${file%.c}.o"
done

# Archive all object files into liball.a
ar rcs liball.a *.o

# Clean up object files
rm -f *.o
