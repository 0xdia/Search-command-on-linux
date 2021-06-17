#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
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

    return argmuents[1];
}

int prendre_niveau(char** arguments, int n)
{
    for (int i=1; i<n; i++) {
        if (arguments[i][0] != '-')
            continue;

        if (strlen(arguments[i]) != 2)
            continue;

        if (argmuents[i][1]>='0' && arguments[i][1]<='9') {
            char num[strlen(argmuents[i])-1];
            strcpy(num, &arguments[i][1]);
            
            return atoi(num);
        }
    }

    return -1;
}

void rechercher(char* chemin, int niveau) // name pattern must be added
{
    DIR* rep;
    struct dirent *entry;
    int ret = 1;
    
    rep = opendir(chemin);

    errno = 0;
    while ((entry = readdir(rep)) != NULL) {
        // check if file name and pattern match here
        if (strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0)
            continue;


        printf("%s: %d\n", entry->d_name, entry->d_type);


        if (entry->d_type == 4) {
            if (niveau == 0)
                continue;

            char chemin_suiv[strlen(chemin) + strlen(entry->d_name) +1];
            strcpy(chemin_suiv, chemin);
            strcat(chemin_suiv, entry->d_name);
            strcat(chemin_suiv, "/");

            if (niveau > 0)
                rechercher(chemin_suiv, niveau-1);
            if (niveau == -1)
                rechercher(chemin_suiv, -1);
        }
    }

    if (errno && !entry)
        perror("readdir");

    closedir(rep);
}
