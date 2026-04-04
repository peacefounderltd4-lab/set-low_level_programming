rm -f libmy.a *.o
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c *.c
ar rcs libmy.a *.o
file libmy.a
ar -t libmy.a
