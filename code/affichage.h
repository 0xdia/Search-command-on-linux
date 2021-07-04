#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

short DATE_CREATION       = 0;
short DATE_DERNIER_ACCES  = 0;
short DATE_DERNIERE_MODIF = 0;
short TAILLE              = 0;
short TYPE                = 0;
short PROTECTION          = 0;
short ALL                 = 0;


void print_protection(struct stat *s)
{
    static const char *rwx[] = {"---", "--x", "-w-", "-wx",
    "r--", "r-x", "rw-", "rwx"};
    static char bits[10];

    int mode = s->st_mode;
    strcpy(&bits[0], rwx[(mode >> 6)& 7]);
    strcpy(&bits[3], rwx[(mode >> 3)& 7]);
    strcpy(&bits[6], rwx[(mode & 7)]);
 
    if (mode & S_ISUID)
        bits[2] = (mode & S_IXUSR) ? 's' : 'S';
    if (mode & S_ISGID)
        bits[5] = (mode & S_IXGRP) ? 's' : 'l';
    if (mode & S_ISVTX)
        bits[8] = (mode & S_IXOTH) ? 't' : 'T';
    bits[9] = '\0';

    printf("%s   ", bits);
    // printf("%3o      ", s->st_mode&0777);
}

void print_type(struct stat *s) // Search for name conventions in french in the course
{
    mode_t t = s->st_mode;
    if (S_ISREG(t))
        printf("Fichier_régulier ");
    else if (S_ISFIFO(t))
        printf("Fichier_spécial ");
    else if (S_ISCHR(t))
        printf("Périph_mode_caractère ");
    else if (S_ISBLK(t))
        printf("Périph_mode_bloc ");
    else if (S_ISDIR(t))
        printf("Répertoire ");
    else if (S_ISLNK(t))
        printf("Lien_symbolique ");
    else if (S_ISSOCK(t))
        printf("Socket ");
    else
        printf("Inconnu ");
}

void print_dernier_acces(struct stat *s)
{
    char time[50];
    strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&s->st_atime));
    printf("%s   ", time);
}

void print_derniere_modif(struct stat *s)
{
    char time[50];
    strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&s->st_mtime));
    printf("%s   ", time);
}

void print_date_creation(struct stat *s)
{
    char time[50];
    strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&s->st_ctime));
    printf("%s   ", time);
}

void print_taille(struct stat *s)
{
    double taille = (double) s->st_size;
    if (taille < 1000) {
        printf("%.1lf B   ", taille);
        return;
    }
    taille /= 1000;
    if (taille < 1000) {
        printf("%.1lf kB   ", taille);
        return;
    }
    taille /= 1000;
    if (taille < 1000) {
        printf("%.1lf MB   ", taille);
        return;
    }
    taille /= 1000;
    printf("%.1lf GB   ", taille);
}

void print_all(struct stat *s, char* nom_fichier)
{
    print_protection(s);
    printf("  ");
    print_taille(s);
    printf(" ");
    print_type(s);
    printf("   ");
    print_dernier_acces(s);
    printf("   ");
    print_derniere_modif(s);
    printf("   ");
    print_date_creation(s);
    printf("  ");
    printf("   %s\n", nom_fichier);
}


void afficher_entete()
{
    if (ALL) {
        printf("Protection    Taille    Type            Dernier acces           Dernière modification          Date de création   ");  
    }
    else {
        if (PROTECTION)
            printf("Protection  ");
        if (TAILLE)
            printf("Taille   ");
        if (TYPE)
            printf("Type        ");
        if (DATE_DERNIER_ACCES)
            printf("Dernier acces   ");
        if (DATE_DERNIERE_MODIF)
            printf("Dernier modification   ");
        if (DATE_CREATION)
            printf("Date de création");
    }
    printf("Nom du fichier\n");
}


void afficher(struct stat *s, char* nom_fichier)
{
    if (ALL) {
        print_all(s, nom_fichier);
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

        printf("   %s\n", nom_fichier);
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
