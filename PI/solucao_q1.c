int solucao_faz_contas(long a, long b, long *c)
{
    if (a > 0)
    {
        *c = 7 * b + 2 * a;
        return 1;
    }
    *c = 5 * a + 9 * b;
    return 0;
}

long solucao_q1(long a, long b)
{
    long local = 0;
    while (local >= 0)
    {
        solucao_faz_contas(a, b, &local);
        a++;
        b -= 2;
    }
    return local;
}