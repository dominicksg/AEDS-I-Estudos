#include <stdio.h>


void printa_n_numeros(FILE *arq, int n)
{
    for (int i = 0; i <= n; i++)
    {
        fprintf(arq, "%d\n", i);
    }
}

int main(void)
{
    FILE *arquivo = fopen("arquivo.txt", "w");
    printa_n_numeros(arquivo, 10);

    return 0;
}
