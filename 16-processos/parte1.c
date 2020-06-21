#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    printf("Eu sou o processo pai, pid=%d, meu id do programa é %d\n",
           getpid(), i);

    for (int i = 1; i < 9; i++)
    {
        if (fork() == 0)
        {
            // processo filho aqui
            printf("Eu sou um processo filho, pid=%d, ppied=%d, meu id do programa é %d\n",
                   getpid(), getppid(), i);
            break;
        }
    }

    return 0;
}
