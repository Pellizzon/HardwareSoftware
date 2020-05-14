#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double sum = 0;
    double j;
    if (argc < 3)
    {
        printf("erro: argumentos faltando\n");
        return 0;
    }
    for (int i = 0; i < argc; i++)
    {
        j = atof(argv[i]);
        sum += j;
    }
    printf("Soma: %lf\n", sum);
    return 0;
}
