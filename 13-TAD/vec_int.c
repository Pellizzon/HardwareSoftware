#include <stdlib.h>

#include "vec_int.h"

typedef struct _vec_int
{
    int *data;
    int size;
    int capacity;
} vec_int;

vec_int *vec_int_create()
{

    vec_int *v = malloc(sizeof(vec_int));
    v->capacity = 2;
    v->data = malloc(2 * sizeof(int));
    v->size = 0;

    return v;
}

void vec_int_destroy(vec_int **_v)
{
    vec_int *v = *_v;
    free(v->data);
    free(v);
    *_v = NULL;
}

int vec_int_size(vec_int *v)
{
    return v->size;
}

int vec_int_at(vec_int *v, int pos, int *val)
{
    if (pos < v->size)
    {
        *val = v->data[pos];
        return 1;
    }
    return 0;
}

int vec_int_insert(vec_int *v, int pos, int val)
{
    if (pos < 0 || pos >= v->capacity)
    {
        return 0;
    }

    v->size++;

    if (v->size == v->capacity)
    {
        v->capacity *= 2;
        v->data = realloc(v->data, sizeof(int) * v->capacity);
    }

    for (int i = v->size - 1; i > pos; i--)
    {
        v->data[i] = v->data[i - 1];
    }
    v->data[pos] = val;

    return 1;
}

int vec_int_remove(vec_int *v, int pos)
{
    if (pos < 0 || pos >= v->size)
    {
        return 0;
    }

    if (v->size == v->capacity / 4)
    {
        v->capacity /= 2;
        v->data = realloc(v->data, sizeof(int) * v->capacity);
    }

    for (int i = pos; i < v->size - 1; i++)
    {
        v->data[i] = v->data[i + 1];
    }

    v->size--;

    return 1;
}
