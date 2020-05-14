#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    pid_t filho;
    int wstatus;
    int rodando = 1;

    while (rodando)
    {
        int n;
        scanf("%d", &n);
        char result[20];
        sprintf(result, "%d\n", n);
        filho = fork();
        if (filho == 0)
        {
            printf("Número digitado: %s\n", result);
            char prog[] = "./eh_par";
            char *args[] = {"eh_par", result, NULL};
            execvp(prog, args);
        }
        else
        {
            wait(&wstatus);
            if ((char)WEXITSTATUS(wstatus) == -1)
            {
                rodando = 0;
            }
            else
            {
                if (WEXITSTATUS(wstatus) == 1)
                {
                    printf("é par\n");
                }
                else
                {
                    printf("não é par\n");
                }
            }
        }
    }
    printf("pragama terminou\n");
    return 0;
}
