#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct
{
    double *vetor;
    int start, end, N, id;
    pthread_mutex_t *m;
    sem_t *s1, *s2;
} var_args;

double soma = 0;
double variancia = 0;

void *computa_media_variancia(void *_arg)
{
    var_args *spa = _arg;

    for (int i = spa->start; i < spa->end; i++)
    {
        pthread_mutex_lock(spa->m);
        soma += spa->vetor[i];
        pthread_mutex_unlock(spa->m);
    }

    switch (spa->id)
    {
    case 0:
        sem_post(spa->s2);
        sem_wait(spa->s1);
        break;

    default:
        sem_post(spa->s1);
        sem_wait(spa->s2);
        break;
    }

    double media = soma / spa->N;
    double var = 0;

    for (int i = spa->start; i < spa->end; i++)
    {
        var += (spa->vetor[i] - media) * (spa->vetor[i] - media);
    }

    pthread_mutex_lock(spa->m);
    variancia += var / spa->N;
    pthread_mutex_unlock(spa->m);

    return NULL;
}

int main(int argc, char *argv[])
{
    double *vetor = NULL;
    int n;
    scanf("%d", &n);

    vetor = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &vetor[i]);
    }

    sem_t s1, s2;
    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 0);

    pthread_t ids[2];
    var_args arg[2];
    pthread_mutex_t m;
    pthread_mutex_init(&m, NULL);
    for (int i = 0; i < 2; i++)
    {
        arg[i].vetor = vetor;
        arg[i].start = i * n / 2;
        arg[i].end = (i + 1) * n / 2;
        arg[i].m = &m;
        arg[i].id = i;
        arg[i].N = n;
        arg[i].s1 = &s1;
        arg[i].s2 = &s2;
        pthread_create(&ids[i], NULL, computa_media_variancia, &arg[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_join(ids[i], NULL);
    }

    pthread_mutex_destroy(&m);
    sem_destroy(&s1);
    sem_destroy(&s2);

    printf("Soma: %lf\n", soma);
    printf("Variancia: %lf\n", variancia);

    return 0;
}
