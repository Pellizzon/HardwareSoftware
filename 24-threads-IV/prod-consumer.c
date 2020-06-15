#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>

typedef struct
{
    int n;
    sem_t *s1, *s2;
} prod_result;

int num;

void *producer(void *_arg)
{
    prod_result *spa = _arg;

    for (int i = 0; i < spa->n; i++)
    {
        sem_wait(spa->s2);
        num = rand() % 10;
        sem_post(spa->s1);

        struct timespec tm;
        tm.tv_sec = 0;

        tm.tv_nsec = num * 100000000;
        nanosleep(&tm, NULL);
    }

    return NULL;
}

void *consumer(void *_arg)
{
    prod_result *spa = _arg;

    for (int i = 0; i < spa->n; i++)
    {
        sem_wait(spa->s1);
        int temp = num;
        sem_post(spa->s2);

        struct timespec tm;
        tm.tv_sec = 0;

        tm.tv_nsec = temp * 300000000;
        nanosleep(&tm, NULL);

        printf("Step: %d, pr->num %d, res %d\n", i, temp, temp * 2);
    }

    return NULL;
}

int main()
{
    int N = 50;

    sem_t s1, s2;
    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 1);

    pthread_mutex_t m;
    pthread_mutex_init(&m, NULL);

    pthread_t id1, id2;

    prod_result arg[2];

    for (int i = 0; i < 2; i++)
    {
        arg[i].s1 = &s1;
        arg[i].s2 = &s2;
        arg[i].n = N;
    }

    pthread_create(&id1, NULL, producer, &arg[0]);
    pthread_create(&id2, NULL, consumer, &arg[1]);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    pthread_mutex_destroy(&m);
    sem_destroy(&s1);
    sem_destroy(&s2);

    return 0;
}

/* TODO: Responda as perguntas abaixo após finalizar sua implementação.


1. Quanto tempo demora a versão original do código?

2. Quanto tempo demora a versão Produtor-Consumidor 1-1? Seu programa deverá ter ganho de desempenho considerável.

3. Como estes tempos se relacionam com os tamanhos dos nanosleep usados nas funções. Você pode assumir que rand() sempre retorna 1.

4. Explique como você fez a sincronização entre as threads. Para cada semáforo explique seu propósito e valor inicial. Para cada mutex aponte qual recurso compartilhado ele protege.

*/
