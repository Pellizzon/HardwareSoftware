#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    pid_t filho;

    filho = fork();

    if (filho == 0)
    {
        int a = 3 / 0;
    }
    else
    {
        int wt;
        wait(&wt);
        printf("WIFEXITED: %d\nWIFSIGNALED: %s\nWTERMSIG: %s\n",
               WIFEXITED(wt), strsignal(WIFSIGNALED(wt)), strsignal(WTERMSIG(wt)));
    }
    return 0;
}
