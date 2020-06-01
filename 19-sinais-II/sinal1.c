#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int num)
{
    static int counter = 0;
    printf(" Chamou Ctrl+C\n");
    counter++;

    //ESSA É A PRIMERIA QUESTÃO DO ROTEIRO
    // if (counter > 2)
    // {
    //     exit(0);
    // }

    //ESSA É A SEGUNDA QUESTÃO DO ROTEIRO
    if (counter)
    {
        struct sigaction s;
        s.sa_handler = SIG_DFL;
        sigemptyset(&s.sa_mask);
        s.sa_flags = 0;

        sigaction(SIGINT, &s, NULL);
    }
}

int main()
{
    /* TODO: registre a função sig_handler
     * como handler do sinal SIGINT
     */

    struct sigaction s;
    s.sa_handler = sig_handler;
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;

    sigaction(SIGINT, &s, NULL);

    printf("Meu pid: %d\n", getpid());

    while (1)
    {
        sleep(1);
    }
    return 0;
}
