#include <stdio.h>
#include <stdlib.h>
#include "recherche.h"

int main(int argc, char** argv)
{
    if (argc < 2)
        puts("Usage: Search [Nom du répertoire] [-option] {Nom du fichier}");
    

    int niveau = (argc > 1) ? (int) (argv[1][1]-'0') : -1;
        

    printf("%d\n", niveau);
    rechercher("/home/dhiaa/Documents/", niveau);
    return 0;
}
