#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros_correcoes.h"

/* Recebe duas strings e concatena em uma terceira */
char *mystrcat(char *str1, char *str2)
{
    int n1, n2, i, j;
    for (n1 = 0; str1[n1]; n1++)
        ;
    n1++;
    for (n2 = 0; str2[n2]; n2++)
        ;
    n2++;

    char *str3 = malloc((n1 + n2) * sizeof(char));

    for (i = 0; i < n1 - 1; i++)
    {
        str3[i] = str1[i];
    }

    for (j = 0; j < n2; j++)
    {
        str3[i + j] = str2[j];
    }
    str3[i + j] = '\0';

    return str3;
}

int main(int argc, char *argv[])
{
#define teste1 "str1"
#define teste2 "str2"
#define teste3 "0 str 3"

    char *res = mystrcat(teste1, teste2);
    assertEquals("teste 1", strcmp(res, teste1 teste2), 0);
    free(res);

    res = mystrcat(teste1, teste1);
    assertEquals("teste 2", strcmp(res, teste1 teste1), 0);
    free(res);

    res = mystrcat(teste1, teste3);
    assertEquals("teste 3", strcmp(res, teste1 teste3), 0);
    free(res);

    res = mystrcat(teste3, teste1);
    assertEquals("teste 4", strcmp(res, teste3 teste1), 0);
    free(res);

    res = mystrcat("", teste2);
    assertEquals("teste vazio 1", strcmp(res, teste2), 0);
    free(res);

    res = mystrcat(teste1, "");
    assertEquals("teste vazio 2", strcmp(res, teste1), 0);
    free(res);

    res = mystrcat("", "");
    assertEquals("teste vazio 3", strcmp(res, ""), 0);
    free(res);

    printSummary

        return 0;
}
