#include <stdio.h>
#include <stdlib.h>
#include "patterns.h"

int main(int argc, char** argv)
{
    if (argc < 3)
        return 0;

    nettoyer_nom(argv[1]);

    printf("%s: %ld\n", argv[1], strlen(argv[1]));
    if (go(argv[1], argv[2]))
        puts("Go!");
    else puts("No Go!");

    puts("");
    if (correspondre(argv[1], 0, argv[2], 0))
        puts("Yes!");
    else puts("No!");

    return 0;
}
