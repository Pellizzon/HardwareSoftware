/* Implementar função solucao_ex2 */

// long vezes2(long a)
// {
//     return a + a;
// }

int solucao_ex2(long a, long b)
{
    long var1 = vezes2(b);
    if (var1 > a)
    {
        a += a;
    }
    var1 += a;
    return var1;
}