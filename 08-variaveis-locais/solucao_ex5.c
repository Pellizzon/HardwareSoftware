int ex5_solucao()
{
    int var1 = 1;
    int var2 = 0;

    while (var1 > 0)
    {
        scanf("%d", &var1);
        if (var1 > 0)
        {
            var2 += var1;
        }
    }
    return var2;
}