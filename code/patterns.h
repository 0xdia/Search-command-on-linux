#include <stdio.h>
#include <string.h>

void nettoyer_nom(char* pattern)
{
    if (strlen(pattern) == 1)
        return;

    char propre[256];
    propre[0] = pattern[0]; 
    
    // enlever les '*' consécutives
    int j = 1;
    for (int i=1; i<strlen(pattern); i++)
    {
        if (pattern[i] == '*') {
            if (propre[j-1] != '*')
                propre[j++] = pattern[i];
        }
        else propre[j++] = pattern[i];
    }

    propre[j] = '\0';

    strcpy(pattern, propre);
}

int go(char* p, char *b)
{
    int min_chars = 0;
    for (int i=0; p[i] != '\0'; i++)
        min_chars += (p[i] != '*');

    return min_chars <= strlen(b);
}

int correspondre(char* p, int cur_p, char* b, int cur_b) 
{
    // printf("[***]: %s x %s\n", &p[cur_p], &b[cur_b]);
    
    if (strcmp(&p[cur_p], &b[cur_b]) == 0) {
        return 1;
    }

    if (p[cur_p] == '\0' && b[cur_b] != '\0') {
        return 0;
    }

    if (p[cur_p] == '*') {
        // puts("Inside *");
        if (p[cur_p+1] == '\0')
            return 1;

        int at_least_at_the_end = 0;
        for (int i=cur_p+1; p[i] != '\0'; i++)
            at_least_at_the_end += (p[i] != '*');
    
        // printf(" at least at the end = %d\n", at_least_at_the_end);

        int chars_remaining = strlen(b) - cur_b;
        
        //for (int i=cur_b, chars_remaining; b[i] != '\n'; i++, chars_remaining++)
        //;

        // printf(" chars remaining = %d\n", chars_remaining);

        if (at_least_at_the_end > chars_remaining)
            return 0;

        // needs a clever optimization using DP
        for (; b[cur_b] != '\0'; cur_b++)
            if (correspondre(p, cur_p+1, b, cur_b))
                return 1;

        return 0;
    }
    
    else if (p[cur_p] == '?') {
        // puts("Inside ?");
        if (p[cur_p+1] == '\0')
            return b[cur_b+1] == '\0';

        if (b[cur_b+1] == '\0')
            return (p[cur_p+1]=='*' && p[cur_p+2]=='\0');
    }
    
    else {
        // printf("Testing 2 chars: ");
        if (p[cur_p] != b[cur_b]) {
            return 0;
        }

        if (p[cur_p+1] == b[cur_b+1] && p[cur_p+1] == '\0') {
            return 1;
        }

    }

    return correspondre(p, cur_p+1, b, cur_b+1);
}

