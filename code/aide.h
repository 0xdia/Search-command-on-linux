#include <stdio.h>
#include <stdlib.h>

void afficher_aide()
{
    puts("Search:");
    puts("Usage:     search  [Nom du répertoire]  [-options]  \"Nom_du_fichier\"");

    puts("Description de la commande:");
    puts("   Une commande de recherchede fichiers sous Linux.");

    puts("Nom du répertoire: entre guillemets");

    puts("Options:");
    puts("          Il existe deux types d'options:");
    puts("              1/ Options du niveau de recherche:");
    puts("                        -0: recherche seulement dans le répertoire \"Nom du répertoire\"");
    puts("                        -1: parcourir un seul niveau de l'arborescence.");
    puts("                        -n: parcourir n niveaux de l'arborescence.");

    puts("                        Si aucune des trois existe, aucune limite ne sera considérée.");
    puts("              2/ Options concernant les informations des fichiers affichés:");
    puts("                        -d: afficher la date de création et la date de la dernière utilisation du fichier");
    puts("                        -m: afficher la date de la dernière modification du fichier");
    puts("                        -s: afficher la taille du fichier");
    puts("                        -t: afficher le type de fichier");
    puts("                        -p: afficher la protection du fichier");
    puts("                        -a: afficher toutes les caractéristiques (d,s,t,p)");
    puts("");                        
    puts("                        Si aucune de ces options existe, -a sera considérée.");

    puts("Nom du fichier:");
    puts("          - Le nom du fichier peut contenir les caractères génériques tels que ? pi *.");
    puts("          - Il faut l'écrire entre guillemets.");
}
