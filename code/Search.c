#include <stdio.h>
#include "patterns.h"

int main(int argc, char** argv)
{
    if (argc < 2)
        puts("Usage: Search [Nom du répertoire] [-option] {Nom du fichier}");

    printf("%s\n", nettoyer_nom(argv[1]));

    return 0;
}
