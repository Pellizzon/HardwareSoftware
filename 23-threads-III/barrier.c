#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct
{
    int id, N;
    pthread_mutex_t *m;
    sem_t *b;
} thread_barrier_args;

int contador = 0;

void *thread_n(void *v)
{
    thread_barrier_args *args = (thread_barrier_args *)v;

    printf("Parte 1 thread %d\n", args->id);

    // TODO: a barreira vai aqui
    pthread_mutex_lock(args->m);
    contador++;
    pthread_mutex_unlock(args->m);

    if (contador == args->N)
    {
        for (int i = 0; i < args->N; i++)
        {
            sem_post(args->b);
        }
    }
    sem_wait(args->b);

    printf("Pós barreira thread %d\n", args->id);

    return NULL;
}

int main()
{
    int N = 10;

    // TODO: inicializar todas variáveis da barreira
    sem_t barrier;
    sem_init(&barrier, 0, 0);

    pthread_mutex_t m;
    pthread_mutex_init(&m, NULL);

    // TODO: criar e esperar N threads
    pthread_t *tids = malloc(N * sizeof(pthread_t));
    thread_barrier_args *argvec = malloc(N * sizeof(thread_barrier_args));

    for (int i = 0; i < N; i++)
    {
        argvec[i].id = i;
        argvec[i].m = &m;
        argvec[i].N = N;
        argvec[i].b = &barrier;
        pthread_create(&tids[i], NULL, thread_n, &argvec[i]);
    }

    for (int i = 0; i < N; i++)
    {
        pthread_join(tids[i], NULL);
    }

    pthread_mutex_destroy(&m);
    sem_destroy(&barrier);

    return 0;
}
