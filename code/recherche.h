#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

/* struct dirent {
 *     ino_t d_ino; // inode number;
 *     off_t d_off; // offset to next dirent 
 *     unsigned short d_reclen; // length of this record
 *     unsigned char d_type; // type of file
 *     char d_name[256]; // file name
 * }
 */

char* prendre_chemin(char** arguments)
{
    if (arguments[1][0] == '-')
        return NULL;

    return arguments[1];
}

int prendre_niveau(char** arguments, int n)
{
    for (int i=1; i<n; i++) {
        if (arguments[i][0] != '-')
            continue;

        if (arguments[i][1]>'9')
            continue;

        if (arguments[i][1]>='0' && arguments[i][1]<='9') {
            char num[strlen(arguments[i])-1];
            strcpy(num, &arguments[i][1]);
            
            return atoi(num);
        }
    }

    return -1;
}

void rechercher(char* chemin, int niveau, char* patrn) // name pattern must be added
{
    DIR* rep;
    struct dirent *entry;
    
    rep = opendir(chemin);

    errno = 0;
    while ((entry = readdir(rep)) != NULL) {
        if (strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0)
            continue;

        struct stat s;

        if (correspondre(patrn, 0, entry->d_name, 0)) {
            char nom_fichier[strlen(chemin) + strlen(entry->d_name)+1];
            strcpy(nom_fichier, chemin);
            strcat(nom_fichier, entry->d_name);

            int ret = stat(nom_fichier, &s);
            if (ret) {
                perror("stat");
                continue;
            }

            afficher(&s, entry->d_name); 
        }

        if (entry->d_type == 4) {
            if (niveau == 0)
                continue;

            char chemin_suiv[strlen(chemin) + strlen(entry->d_name) +1];
            strcpy(chemin_suiv, chemin);
            strcat(chemin_suiv, entry->d_name);
            strcat(chemin_suiv, "/");

            if (niveau > 0)
                rechercher(chemin_suiv, niveau-1, patrn);
            if (niveau == -1)
                rechercher(chemin_suiv, -1, patrn);
        }
    }

    if (errno && !entry)
        perror("readdir");

    closedir(rep);
}
