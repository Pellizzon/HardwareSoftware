#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros_correcoes.h"

char *mystrcpy(char *stroriginal)
{
    int n;
    for (n = 0; stroriginal[n]; n++)
        ;
    //por causa o "\0"
    n++;
    char *strcopia = malloc(n * sizeof(char));

    for (int i = 0; i < n; i++)
    {
        strcopia[i] = stroriginal[i];
    }

    return strcopia;
}

int main(int argc, char *argv[])
{
    //char *strcopia;

    char *s1 = "AAAAA";
    char *t1 = mystrcpy(s1);
    assertEquals("Teste 1", strcmp(s1, t1), 0);
    free(t1);

    s1 = "";
    t1 = mystrcpy(s1);
    assertEquals("Teste 2", strcmp(s1, t1), 0);
    free(t1);

    s1 = "AaAa123384739jlkfjdsl";
    t1 = mystrcpy(s1);
    assertEquals("Teste 3", strcmp(s1, t1), 0);
    free(t1);

    s1 = "Aa00asdsada";
    t1 = mystrcpy(s1);
    assertEquals("Teste 4", strcmp(s1, t1), 0);
    free(t1);

    s1 = "0asgfd";
    t1 = mystrcpy(s1);
    assertEquals("Teste 5", strcmp(s1, t1), 0);
    free(t1);

    printSummary

        return 0;
}
