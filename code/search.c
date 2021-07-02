#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "affichage.h"
#include "recherche.h"
#include "patterns.h"
#include "verification.h"

int main(int argc, char** argv)
{
    if (verifier_entree(argc, argv) == 0)
        return 0;


    specifier_parametres(argv, argc);
    

    int niveau = prendre_niveau(argv, argc);

    nettoyer_nom(argv[argc-1]);

    /*
    if (! go(argv[argc-2], argv[argc-1])) {
        puts("No file was found");
        return 0;
    }
    */

    
    char* chemin_rep = ".";
    if (argc > 2)   
        chemin_rep = prendre_chemin(argv);

    /*
    char *cwd;
    cwd = getcwd(chemin_rep, 0);
    if (!cwd) {
        perror("getcwd");
        return 1;
    }
    free(cwd);
    */

    rechercher(chemin_rep, niveau, argv[argc-1]);
    if (! entete_deja_affiche)
        puts("Aucun fichier n'est trouvé");

    return 0;
}
