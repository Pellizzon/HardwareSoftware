
/* Implemente aqui sua versão em C da função soma_n
 * presente no arquivo ex4.o
 * 
 * Chame sua função de soma_n_solucao */

int soma_n_solucao(int a)
{
    int c = 0;
    long var = 0;
    while (c < a)
    {
        var += c;
        c++;
    }
    return var;
}