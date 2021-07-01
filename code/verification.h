#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include "aide.h"

int repertoire_existe(char* chemin)
{
    DIR* dir = opendir(chemin);
    if (dir) {
        // le répertoire existe
        closedir(dir);
        return 1;
    } else if (ENOENT == errno) {
        puts("le répertoire n'existe pas");
        return 0;
    }

    return 0;
}

int entree_erronee(int t, char** arguments)
{
    if (t < 2)
        return 1;
    
    int non_options = 0;
    int options_niveau = 0;

    for (int i=1; i<t-1; i++) {
        if (arguments[i][0] != '-') {
            ++non_options;
            continue;
        }

        // vérifier s'il s'agit d'une option de niveau
        if (strlen(arguments[i])>=2) {
            int cont = 1;
            for (int j=1; j<strlen(arguments[i]) && (cont=(arguments[i][j]>='0' && arguments[i][j]<='9')); j++)
                ;

            if (cont)
                continue;
        }

        if (
            strcmp(arguments[i], "-0") &&
            strcmp(arguments[i], "-1") &&
            // strcmp(arguments[i], "-n") &&
            strcmp(arguments[i], "-d") &&
            strcmp(arguments[i], "-m") &&
            strcmp(arguments[i], "-s") &&
            strcmp(arguments[i], "-t") &&
            strcmp(arguments[i], "-p") &&
            strcmp(arguments[i], "-a")
           )
            return 1;

        options_niveau += (arguments[i][1]>='0' && arguments[i][1]<='9');
    }

    if (non_options > 2)
        return 1;
    
    if (options_niveau > 1)
        return 1;

    if (arguments[1][0] == '-' || arguments[t-1][0] == '-')
        return 1;

    // vérifier si le répertoire existe
    if (t>2 && ! repertoire_existe(arguments[1]))
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
