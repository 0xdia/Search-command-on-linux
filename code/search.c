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

    char pat[60];
    nettoyer_nom(argv[argc-1], pat);

    char* chemin_rep;
    chemin_rep = getcwd(NULL, 0);
    if (! chemin_rep) {
        perror("getcwd");
        exit(1);
    }
    
    strcpy(chemin_rep, prendre_chemin(chemin_rep));

    if (argc > 2) {  
        if (strcmp(argv[1], ".") && argv[1][0]!='-')
            strcpy(chemin_rep, prendre_chemin(argv[1]));
        else
            strcpy(chemin_rep, prendre_chemin(chemin_rep));
    } 
        
    /*
    printf("[***] Arguments: %d\n", argc);
    for (int i=0; i<argc; i++)
        printf("%s ", argv[i]);
    puts("");
    puts("[***]");

    printf("[*] pattern: %s [end]\n", pat);
    printf("[*] chemin: %s\n", chemin_rep);
    */

    rechercher(chemin_rep, niveau, pat);
    if (! entete_deja_affiche)
        puts("Aucun fichier n'est trouvé");

    free(chemin_rep);  
    return 0;
}
