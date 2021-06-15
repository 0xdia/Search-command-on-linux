#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "affichage.h"
#include "recherche.h"
#include "patterns.h"

int main(int argc, char** argv)
{
    if (argc < 2)
        puts("Usage: Search [Nom du répertoire] [-option] {Nom du fichier}");
    

    int niveau = (argc > 1) ? (int) (argv[1][1]-'0') : -1;
        


    char *cwd;
    cwd = getcwd(NULL, 0);
    if (!cwd) {
        perror("getcwd");
        return 1;
    }

    /*
    if (chdir("/"))
        perror("chdir");

    printf("%s\n", getcwd(NULL, 0));
    */

    specifier_parametres(argv, argc);

    strcat(cwd, "/Search.c");


    struct stat s;

    int ret = stat(cwd, &s);
   

    if (ret) {
        perror("stat");
        return 1;
    }

    afficher(&s);
    free(cwd);

    printf("%d\n", niveau);
    rechercher("/home/dhiaa/Documents/", niveau);
    return 0;
}
