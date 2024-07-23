#include <stdio.h>

int main(void)
{
    float numero[2];
    float aux;
    float soma;
    float media = 0;

    FILE *arquivo = fopen("arquivo.txt", "r");
    while (fscanf(arquivo, "%f", &aux) != EOF)
    {
        if (aux > numero[0])
        {
            numero[0] = aux;
        }
    }
    fclose(arquivo);

    numero[1] = numero[2];
    
    arquivo = fopen("arquivo.txt", "r");
    while (fscanf(arquivo, "%f", &aux) != EOF)
    {
        if (aux < numero[1])
        {
            numero[1] = aux;
        }
    }
    fclose(arquivo);

    arquivo = fopen("arquivo.txt", "r");
    while (fscanf(arquivo, "%f", &aux) != EOF)
    {
        soma += aux;
        media++;
    }
    fclose(arquivo);

    media = soma / media;

    printf("O maior numero e %f\n", numero[0]);
    printf("O menor numero e %f\n", numero[1]);

    printf("A media e %f", media);

    return 0;
}