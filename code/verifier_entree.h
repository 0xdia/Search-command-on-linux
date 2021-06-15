#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aide.h"

int entree_erronee(int t, char** arguments)
{
    if (t < 2)
        return 1;
    
    int non_options = 0;

    for (int i=1; i<t; i++) {
        if (arguments[i][0] != '-') {
            ++non_options;
            continue;
        }

        if (
            strcmp(arguments[i], "-0") &&
            strcmp(arguments[i], "-1") &&
            strcmp(arguments[i], "-n") &&
            strcmp(arguments[i], "-d") &&
            strcmp(arguments[i], "-m") &&
            strcmp(arguments[i], "-s") &&
            strcmp(arguments[i], "-t") &&
            strcmp(argmuents[i], "-p") &&
            strcmp(argmuents[i], "-a")
           )
            return 1;
    }

    if (non_options > 2)
        return 1;
    
    if (arguments[1][0] == '-' || arguments[t-1][0] == '-')
        return 1;

    if (! repertoire_existe(arguments[1]))
        return 1;

    return 0;
}

int verifier_entree(int t, char** arguments)
{
    if (entree_erronee(t, arguments)) {
        afficher_aide();
        return 0;
    }
    
    return 1;
}
