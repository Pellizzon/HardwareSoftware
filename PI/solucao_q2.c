int solucao_q2(int a)
{
    if (a <= 0)
    {
        return -1;
    }
    int var = 0;
    while (a > 0)
    {
        a += a;
        var++;
    }
    return var * 45;
}