
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct args
{
    int i, j, res;
};

void *tarefa_print_i(void *arg)
{
    int *i = (int *)arg;
    printf("%d\n", *i);
    return NULL;
}

int main()
{
    int n = 4;
    int *vi = malloc(n * sizeof(int));
    pthread_t *tids = malloc(n * sizeof(pthread_t));
    pthread_t tid;
    for (int i = 0; i < n; i++)
    {
        vi[i] = i;
        pthread_create(&tid, NULL, tarefa_print_i, &vi[i]);
        tids[i] = tid;
    }

    for (int i = 0; i < n; i++)
    {
        pthread_join(tids[i], NULL);
    }

    return 0;
}