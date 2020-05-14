#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("erro: argumentos faltando\n");
        return -1;
    }
    if (atol(argv[1]) < 0)
    {
        return -1;
    }
    else if (atol(argv[1]) % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
