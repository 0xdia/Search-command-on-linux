#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

short DATE_CREATION       = 0;
short DATE_DERNIER_ACCES  = 0;
short DATE_DERNIERE_MODIF = 0;
short TAILLE              = 0;
short TYPE                = 0;
short PROTECTION          = 0;
short ALL                 = 0;


void print_protection(struct stat *s)
{
    // re-write this function later
    printf("%3o      ", s->st_mode&0777);
}

void print_type(struct stat *s) // Search for name conventions in french in the course
{
    mode_t t = s->st_mode;
    if (S_ISREG(t))
        printf("Fichier régulier ");
    if (S_ISFIFO(t))
        printf("Fichier spécial ");
    if (S_ISCHR(t))
        printf("Périph mode caractère ");
    if (S_ISBLK(t))
        printf("Périph mode bloc ");
    if (S_ISDIR(t))
        printf("Répertoire ");
    if (S_ISLNK(t))
        printf("Lien symbolique ");
    if (S_ISSOCK(t))
        printf("Socket ");
}

void print_dernier_acces(struct stat *s)
{
    printf("%ld ", s->st_atime); 
}

void print_derniere_modif(struct stat *s)
{
    printf("%ld ", s->st_mtime);
}

void print_date_creation(struct stat *s)
{
    // how to obtain this ?
    printf("Birth date");
}

void print_taille(struct stat *s)
{
    printf("%ld ", s->st_size);
}

void print_all(struct stat *s)
{
    print_protection(s);
    print_taille(s);
    print_type(s);
    print_dernier_acces(s);
    print_derniere_modif(s);
    puts("");
}


void afficher_entete()
{
    if (ALL) {
        printf("Protection  Taille  Type  Dernier acces  Dernière modification  Date de création\n");  
    }
    else {
        if (PROTECTION)
            printf("Protection ");
        if (TAILLE)
            printf("Taille ");
        if (TYPE)
            printf("Type ");
        if (DATE_DERNIER_ACCES)
            printf("Dernier acces ");
        if (DATE_DERNIERE_MODIF)
            printf("Dernier modification ");
        if (DATE_CREATION)
            printf("Date de création");

        puts("");
    }
}


void afficher(struct stat *s)
{
    afficher_entete();

    if (ALL) {
        print_all(s);
    }
    else {
        if (PROTECTION)
            print_protection(s);
        if (TAILLE)
            print_taille(s);
        if (TYPE)
            print_type(s);
        if (DATE_DERNIER_ACCES)
            print_dernier_acces(s);
        if (DATE_DERNIERE_MODIF)
            print_derniere_modif(s);
        if (DATE_CREATION)
            print_date_creation(s);

        puts("");
    }

}

void specifier_parametres(char* param[], int n)
{
    for (int i=1; i<n; i++) {
        if (! strcmp(param[i], "-d"))
            DATE_CREATION = DATE_DERNIER_ACCES = 1;
        if (! strcmp(param[i], "-m"))
            DATE_DERNIERE_MODIF = 1;
        if (! strcmp(param[i], "-s"))
            TAILLE = 1;
        if (! strcmp(param[i], "-t"))
            TYPE   = 1;
        if (! strcmp(param[i], "-p"))
            PROTECTION = 1;
        if (! strcmp(param[i], "-a"))
            ALL = 1;
    }

    if (!(ALL||DATE_CREATION||DATE_DERNIER_ACCES||DATE_DERNIERE_MODIF||TAILLE||TYPE||PROTECTION))
        ALL = 1;
}
