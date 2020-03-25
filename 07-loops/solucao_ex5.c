
/* Implemente aqui sua versão em C da função ex5
 * presente no arquivo ex5.o
 * 
 * Chame sua função de ex5_solucao */
long ex5_solucao(long a, long b)
{
    long q = 0;
    for (long x = 0; x < a; x++)
    {
        long resto = x % b;
        if (resto == 0)
        {
            q += x;
        }
    }
    return q;
}