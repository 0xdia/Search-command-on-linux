#include <stdio.h>
#include <string.h>


char* nettoyer_nom(char* pattern)
{
    char *propre = "";
    propre = pattern[0]; 

    // enlever les '*' consécutives
    for (int i=1; i<strlen(pattern); i++)
    {
        if (pettern[i] == '*')
            if (propre[strlen(propre)-1] != '*')
                strcat(propre, pattern[i]);
    }

    return propre;
}

int correspondre(char* a, char* b) 
{
    return 0;
}

