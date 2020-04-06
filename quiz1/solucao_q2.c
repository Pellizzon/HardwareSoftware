// Comando para compilar seu programa:
// gcc -Og solucao_q2.c q2.o -o q2

// TODO: implementar solucao_q2 abaixo

void solucao_q2(unsigned long a, unsigned long b, int *c)
{
    while (a > 1)
    {
        a /= 2;
        (*c) += 10;
    }

    while (b > 50)
    {
        b /= 8;
        (*c) -= 7;
    }
}