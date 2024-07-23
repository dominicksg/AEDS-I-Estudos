#include <stdio.h>

void processarMatriz(int linhas, int colunas, int matriz[][colunas]);

void printeEae(char opa[]);

int main()
{
    char eae[5] = {0, 1, 2, 3, 4};
    int n = 5;

    int matrizExemplo[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int linhas = 3;
    int colunas = 3;

    // Chamada da função com a matriz como argumento
    printeEae(eae);
    printf("\n");
    processarMatriz(linhas, colunas, matrizExemplo);

    return 0;
}

void printeEae(char opa[])
{
    // Printe os elementos do array eae
    /*
        for (int i = 0; i < tamanho; i++)
        {
            printf("%d ", opa[i]);
        }
    */
    printf("%d ", opa[0]);
    printf("\n");
}

void processarMatriz(int linhas, int colunas, int matriz[][colunas])
{
    // Faça algo com a matriz
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}