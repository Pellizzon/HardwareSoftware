#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

struct args
{
    int size;
    double v[10], res;
};

void *minha_thread(void *_arg)
{
    struct args *args = (struct args *)_arg;
    double value = 0;
    for (int i = 0; i < args->size; i++)
    {

        value += args->v[i];
    }

    args->res = value;

    return NULL;
}

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    int n = 2;
    int size1 = num / 2;
    int size2;
    char impar;
    if (num % 2 == 1)
    {
        size2 = size1 + 1;
        impar = 1;
    }
    else
    {
        size2 = size1;
        impar = 0;
    }

    pthread_t *tids = malloc(n * sizeof(pthread_t));
    struct args *argvec = malloc(n * sizeof(struct args));

    argvec[0].size = size1;
    argvec[1].size = size2;

    for (int i = 0; i < size1; i++)
    {
        argvec[0].v[i] = atof(argv[2 + i]);
    }

    for (int i = 0; i < size2; i++)
    {
        if (!impar)
            argvec[1].v[i] = atof(argv[2 + size2 + i]);
        if (impar)
            argvec[1].v[i] = atof(argv[1 + size2 + i]);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_create(&tids[i], NULL, minha_thread, &argvec[i]);
    }

    for (int i = 0; i < n; i++)
    {
        pthread_join(tids[i], NULL);
    }

    printf("Soma: %lf\n", argvec[0].res + argvec[1].res);

    return 0;
}
