#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

short DATE_CREATION       = 0;
short DATE_DENRIER_ACCES  = 0;
short DATE_DERNIERE_MODIF = 0;
short TAILLE              = 0;
short TYPE                = 0;
short PROTECTION          = 0;
short ALL                 = 0;

void afficher(struct stat *s)
{
    if (ALL) {
        printf("Protection  Taille  Type  Dernier acces  Dernière modification  Date de mréation\n");  
    }
    else {
        if (PROTECTION)
            printf("Protection ");
        if (TAILLE)
            printf("Taille ");
        if (TYPE)
            printf("Type ");
        if (DATE_DENRIER_ACCES)
            printf("Dernier acces ");
        if (DATE_DERNIERE_MODIF)
            printf("Dernier modification ");
        if (DATE_CREATION)
            printf("Date de création");

        puts("");
    }

    if (ALL) {
        print_all(s);
    }
    else {
        if (PROTECTION)
            print_protection();
        if (TAILLE)
            print_taille();
        if (TYPE)
            print_type();
        if (DATE_DENRIER_ACCES)
            print_dernier_acces();
        if (DATE_DERNIERE_MODIF)
            print_derniere_modif();
        if (DATE_CREATION)
            print_date_creation();

        puts("");
    }

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

void print_protection(struct stat *s)
{
    // re-write this function later
    printf("%3o ", s->st_mode&0777);
}

void print_type(struct stat *s) // Search for name conventions in french in the course
{
    switch (s->st_mode & S_IFMT) {
        case S_IFBLK:
            printf("Block device node ");
            break;
        case S_IFCHR:
            printf("Character device node ");
            break;
        case S_IFDIR:
            printf("Directory ");
            break;
        case S_IFIFO:
            printf("FIFO ");
            break;
        case S_IFLNK:
            printf("Symbolic link ");
            break;
        case S_IFREG:
            printf("Regular file ");
            break;
        case S_IFSOCK:
            printf("Socket ");
            break;
        default:
            printf("Unkown ");
            break;
    }
}

void print_dernier_acces(struct stat *s)
{
    printf("%lld ", s->st_atime); 
}

void print_derniere_modif(struct stat *s)
{
    printf("%lld ", s->mtime);
}

void print_date_creation(struct stat *s)
{
    // how to obtain this ?
}
