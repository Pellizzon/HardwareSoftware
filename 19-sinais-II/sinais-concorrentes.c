#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int status = 0;

void operacao_lenta()
{
    sleep(10);
}

void sigint_handler(int num)
{
    status += 1;
    printf("Chamou Ctrl+C; status=%d\n", status);
    operacao_lenta();
    printf("SIGINT: Vou usar status agora! status=%d\n", status);
}

void sigterm_handler(int num)
{
    status += 1;
    printf("Recebi SIGTERM; status=%d\n", status);
    operacao_lenta();
    printf("SIGTERM: Vou usar status agora! status=%d\n", status);
}

int main()
{
    /* TODO: registar SIGINT aqui. */
    struct sigaction i, t;
    i.sa_handler = sigint_handler;
    sigemptyset(&i.sa_mask);
    sigaddset(&i.sa_mask, SIGTERM);
    i.sa_flags = 0;

    sigaction(SIGINT, &i, NULL);

    /* TODO: registar SIGTERM aqui. */
    t.sa_handler = sigterm_handler;
    sigemptyset(&t.sa_mask);
    sigaddset(&t.sa_mask, SIGINT);
    t.sa_flags = 0;

    sigaction(SIGTERM, &t, NULL);

    printf("Meu pid: %d\n", getpid());

    while (1)
    {
        sleep(1);
    }
    return 0;
}
