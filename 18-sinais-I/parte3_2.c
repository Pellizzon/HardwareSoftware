#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

int main()
{
    pid_t filho;

    filho = fork();
    if (filho == 0)
    {
        filho = getpid();
        printf("filho: %d\n", filho);
        while (1)
        {
        }
    }
    else
    {
        int wt;

        if (waitpid(filho, &wt, WNOHANG) == 0)
        {
            kill(filho, SIGKILL);
            wait(&wt);
        }

        printf("WIFEXITED: %d\nWIFSIGNALED: %d\nWTERMSIG: %s\n",
               WIFEXITED(wt), WIFSIGNALED(wt), strsignal(WTERMSIG(wt)));
    }
    return 0;
}