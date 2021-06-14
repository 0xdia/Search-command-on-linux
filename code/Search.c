#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include "recherche.h"
=======
#include <unistd.h>
#include "affichage.h"
>>>>>>> 2d83d45c620fcb159dc69befd4f0d25e4d4a360c

int main(int argc, char** argv)
{
    if (argc < 2) {
        puts("Usage: Search [Nom du répertoire] [-option] {Nom du fichier}");
<<<<<<< HEAD
    

    int niveau = (argc > 1) ? (int) (argv[1][1]-'0') : -1;
        
=======
        return 0;
    }


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
>>>>>>> 2d83d45c620fcb159dc69befd4f0d25e4d4a360c

    printf("%d\n", niveau);
    rechercher("/home/dhiaa/Documents/", niveau);
    return 0;
}
