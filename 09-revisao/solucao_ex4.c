/* Implementar solucao_ex4 */

int solucao_ex4(unsigned int a)
{
    unsigned int var = 0;
    while (var < a)
    {
        var = mais_um(var);
    }

    return var;
}