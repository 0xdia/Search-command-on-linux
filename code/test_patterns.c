#include <stdio.h>
#include <stdlib.h>
#include "patterns.h"

int main(int argc, char** argv)
{
    if (argc < 3)
        return 0;

    nettoyer_nom(argv[1]);

    if (! go(argv[1], argv[2])) {
        return 0;

    return 0;
}
