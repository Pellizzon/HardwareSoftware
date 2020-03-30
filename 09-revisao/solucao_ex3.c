void solucao_ex3(long a, long b, int *c, int *d, int *e)
{
    *c = (unsigned int)(a < b);
    *d = (unsigned int)(a == b);
    *e = (unsigned int)(a > b);
}