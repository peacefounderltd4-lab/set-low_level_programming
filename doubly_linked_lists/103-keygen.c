#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *user;
    unsigned int i, len, sum = 0;
    char key[64];

    if (argc != 2)
        return 1;

    user = argv[1];
    len = strlen(user);

    for (i = 0; i < len; i++)
        sum += user[i] * (i + 1);

    srand(sum);

    for (i = 0; i < 10; i++)
        key[i] = 33 + (rand() % 94);

    key[10] = '\0';

    printf("%s\n", key);
    return 0;
}
