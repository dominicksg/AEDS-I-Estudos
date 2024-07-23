#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    char caractere;
    int repete = 0;
    // Inicializa o gerador de números aleatórios com base no tempo atual
    srand(time(NULL));

    // Abre o arquivo para escrita
    FILE *arquivo = fopen("arquivo.txt", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1; // Encerra o programa com um código de erro
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // Gera uma letra aleatória (ASCII) e a escreve no arquivo
        char letra = rand() % 26 + 'A'; // Adiciona o valor ASCII de 'A' ao resultado, então gera uma letra maiúscula aleatória
        fprintf(arquivo, "%c\n", letra);
    }
    fclose(arquivo);

    arquivo = fopen("arquivo.txt", "r");

    while ((caractere = fgetc(arquivo)) != EOF)
    {
        if (caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U')
        {
            repete++;
        }
    }

    printf("existem %d vogais no arquivo", repete);

    // Fecha o arquivo
    fclose(arquivo);
}