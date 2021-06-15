#include <stdio.h>
#include <stdlib.h>

void afficher_aide()
{
    puts("Search:");
    puts("Usage:     search  [Nom du répertoire]  [-options]  Nom_du_fichier");

    puts("Description de la commande:");
    puts("   ...");

    puts("Nom du répertoire:");

    puts("Options:");
    puts("          Il existe deux types d'options:");
    puts("              1/ Options du niveau de recherche:
                            -0: recherche seulement dans le répertoire \"Nom du répertoire\"
                            -1: parcourir un seul niveau de l'arborescence.
                            -n: parcourir n niveaux de l'arborescence.

                            Si aucune des trois existe, aucune limite ne sera considérée.");
    puts("              2/ Options concernant les informations des fichiers affichés:
                            -d:
                            -m:
                            -s:
                            -t:
                            -p:
                            -a:
                            
                            Si aucune de ces options existe, -a sera considérée.");

    puts("Nom du fichier:
            \* est non pas *");
}
