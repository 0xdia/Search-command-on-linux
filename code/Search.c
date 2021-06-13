#include <stdio.h>
#include <unistd.h>
#include "affichage.h"

int main(int argc, char** argv)
{
    if (argc < 2) {
        puts("Usage: Search [Nom du répertoire] [-option] {Nom du fichier}");
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

    return 0;
}
